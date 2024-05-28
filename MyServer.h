#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include<string>
#include <stdexcept> 

class MyServer{
private:
    int server_fd, new_socket;
    ssize_t valread;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = { 0 };
public:
    MyServer(const uint16_t& PORT);
    ~MyServer();

    MyServer(const MyServer&) = delete;
    MyServer& operator=(const MyServer&) = delete;

    void Accept();
    std::string Read();
};
