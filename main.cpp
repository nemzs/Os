#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include <sys/epoll.h>
#include<arpa/inet.h> //inet_addr
#include <array>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <thread>
#include <thread>
#include <set>
#include <map>
#include <cmath>
#include <fstream>

using namespace ::std;

int set_non_blocking(int sockfd) {
    fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
    return 0;
}
//

const int T = 10, X = 10;

string output_file = "result.txt";

int socket_count = T * X; // total socket count = time send * count packets
int epfd = -1;
bool finished = false;
auto send_started = std::chrono::system_clock::now();
map<int, chrono::system_clock::time_point> send_packet_time, receive_packet_time;

vector<int> socket_pool;

void send_requests() {
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    //IP
    server.sin_addr.s_addr = inet_addr("64.233.163.94");
    //Port
    server.sin_port = htons(80);

    //Create socket
    auto send_started = std::chrono::system_clock::now();
    char *message = "GET /\n\n";
    struct epoll_event ev[socket_count];
    int sent = 0;
    while (!finished) {
        auto cur_time = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = cur_time - send_started;
        for (int i = sent; i < min(floor(diff.count()) * X, (double) socket_count); i++) {
            if (floor(diff.count()) * X - sent > X) cout << "Can't connect enough fast sockets to server" << endl;
            cout << sent << " requests already sent and " << socket_count << " left" << endl;
            int tmp = socket(AF_INET, SOCK_STREAM, 0);
            socket_pool.push_back(tmp);
            //connecting
            if (connect(socket_pool[i], (struct sockaddr *) &server, sizeof(server)) < 0) {//nearly 1 sec for 50 soc
                puts("connect error");
                return;
            }
            ev[i].events = EPOLLIN | EPOLLPRI | EPOLLERR | EPOLLHUP | EPOLLET;
            ev[i].data.fd = socket_pool[i];

            epoll_ctl(epfd, EPOLL_CTL_ADD, socket_pool[i], &ev[i]);
            auto time_send = std::chrono::system_clock::now();
            send_packet_time[tmp] = std::chrono::system_clock::now();
            if (send(socket_pool[i], message, strlen(message), 0) < 0) {
                puts("Send failed");
                return;
            }
            sent++;
            set_non_blocking(socket_pool[i]);
        }
    }
}

//epoll is here
void resive_response() {
    struct epoll_event events[socket_count];
    char server_reply[8];

    int open_connections = socket_count;
    set<int> received;
    received.clear();

    std::chrono::duration<double> diff;
    while (open_connections > received.size()) {
        // ожидаем момента, когда надо будет работать...
        int nfds = epoll_wait(epfd, events,
                              open_connections,
                              1000);
        // для каждого готового сокета
        for (int i = 0; i < nfds; i++) {
            int fd = events[i].data.fd;
            receive_packet_time[fd] = std::chrono::system_clock::now();
            received.insert(fd);
            ssize_t respLen;
            //в данном месте используется блокуруемая версия чтения в буфер
            while ((respLen = recv(fd, server_reply, 8, 0)) > 0) {
                //printf("%.*s", respLen, server_reply);
            }
        }
    };

    ofstream results;
    results.open (output_file);
    for(int i=0;i<T;i++){
        double average_delay = 0;
        for(int j=0;j<X;j++){
            int index = i*X+j;
            int fd = socket_pool[index];
            diff = receive_packet_time[fd] - send_packet_time[fd];
            average_delay += diff.count();
        }
        average_delay/=X;
        results<<"Average delay for "<<X<<" requests is "<<average_delay<<" seconds"<<endl;
    }
    for (int i = 0; i < socket_pool.size(); i++) {
        int fd = socket_pool[i];
        diff = receive_packet_time[fd] - send_packet_time[fd];
        results <<"request #"<< i << " delay " << diff.count() * 1000 << " ms ";
        diff = send_packet_time[fd] - send_started;
        results <<"sent "<< diff.count()-1 << " sec after start" << endl;
    }
    results.close();
    finished = true;
    cout << "Last received" << endl;
}
int main(int argc, char *argv[]) {
    epfd = epoll_create(socket_count);
    thread sendThread(send_requests);
    thread epollThread(resive_response);
    sendThread.join();
    epollThread.join();
    return 0;
}
