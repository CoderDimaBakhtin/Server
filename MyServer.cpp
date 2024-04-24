


#include"MyServer.h"


MyServer::MyServer(const uint16_t& PORT){//Creation of the socket and preparation to accept

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw std::invalid_argument("\nsocket failed \n");
    }
 
    
    if (setsockopt(server_fd, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt))) {
        throw std::invalid_argument("\nsetsockopt failed \n");
    }

    if (bind(server_fd, (struct sockaddr*)&address,sizeof(address))< 0) {
        throw std::invalid_argument("\nbind failed \n");
    }
    if (listen(server_fd, 3) < 0) {
        throw std::invalid_argument("\nlisten failure \n");
    }
}


void MyServer::Accept(){
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address,&addrlen))< 0) {
        throw std::invalid_argument("\nAccept failure \n");
    }


}

std::string MyServer::Read(){
    ssize_t valread = read(new_socket, buffer, sizeof(buffer) - 1);
    if (valread == -1) {//Reading Error
        return "-1";
    } else if (valread == 0) {
        printf("\nConnection closed by the Client\n");
        return "0";
    } else {
        buffer[valread] = '\0';
    }    

   
    std::string str(buffer);
    return str;
}



MyServer::~MyServer(){
    close(new_socket);
    close(server_fd);

}








