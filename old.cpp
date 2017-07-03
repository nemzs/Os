#include <string>
#include <winsock.h>
#include <stdio.h>
#include <ctime>

int get_addr(char *host_name)
{
    int res = -1;

    HOSTENT *phe = gethostbyname(host_name);
    if (phe)
        for (int i = 0; i < 4; i++)
            ((BYTE *)&res)[i] = phe->h_addr_list[0][i];

    return res;
}

int main(int argc, char* argv[])
{
    WSADATA wsa_data;
    if (WSAStartup(0x101, &wsa_data))
    {
        printf("WSAStartup error (%i)\n", WSAGetLastError());
        system("pause");
        return -1;
    }

    if (wsa_data.wVersion != 0x101)
    {
        printf("Bad WSA version (%i)\n", wsa_data.wVersion);
        system("pause");
        return -1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET)
    {
        printf("socket error (%i)\n", WSAGetLastError());
        system("pause");
        return -1;
    }

    int use_host_name;
    char host_name[256];
    char host_ip[256];
    int host_port;
    char doc[256];

    /*printf("use_host_name (0 for host_ip or 1 for host_name): ");
    scanf("%i", &use_host_name);

    if (use_host_name)
    {
        printf("host_name: ");
        //scanf("%s", host_name);
    }
    else
    {
        printf("host_ip: ");
        scanf("%s", host_ip);
    }*/
    //printf("host_port: ");
    //scanf("%i", &host_port);
    //std::string str_host_name = "neerc.ifmo.ru";
    std::string str_host_name = "vk.com";
    std::string str_doc = "/";
    strcpy(host_name, str_host_name.c_str());
    strcpy(doc, str_doc.c_str());
    host_port = 80;
    use_host_name = 1;
    /*printf("doc (for example /index.htm or /): ");
    scanf("%s", doc);*/
    printf("Request to %s%s\n",host_name,doc);

    SOCKADDR_IN sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(host_port);
    sa.sin_addr.S_un.S_addr = use_host_name? get_addr(host_name) : inet_addr(host_ip);

    printf("wait for server...\n");

    while (true)
    {
        int connect_res = connect(s, (SOCKADDR *)&sa, sizeof(sa));
        if (!connect_res) break;

        Sleep(250);
    }

    printf("connected\n");

    char message[256];

    int message_size = sprintf
    (
        message,
        "GET [url]http://%s:%i%s[/url] HTTP/1.1\r\n"
        "Host: %s:%i\r\n"
        "Connection: Close\r\n"
        "\r\n",
        (use_host_name? host_name : host_ip),
        host_port,
        doc,
        (use_host_name? host_name : host_ip),
        host_port
    );
        unsigned int start_time = clock();
    for(int i=0;i<10000;i++){
        if (send(s, message, message_size, 0) == SOCKET_ERROR)
        {
            printf("send error (%i)\n", WSAGetLastError());
            system("pause");
            return -1;
        }

        char buffer[100000];
        int buffer_size = sizeof(buffer);
        /*buffer_size = recv(s, buffer, buffer_size, 0);
        if (buffer_size == SOCKET_ERROR)
        {
            printf("recv error (%i)\n", WSAGetLastError());
            system("pause");
            return -1;
        }
        buffer[buffer_size] = '\0';*/
        //printf("from_server: time %i\n%s\n", start_time-response_time, buffer);
    }
    unsigned int response_time = clock();
    printf("from_server: time %i\n", response_time-start_time);
    closesocket(s);
    WSACleanup();


    system("pause");
    return 0;
}
