
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <csignal>

#include"MyServer.h"
#include"FileHandler.h"

// Both client and server have to be in one github repo
// Provide more logging to client as it is not easy to understand that it is working properly

int main(int argc, char const* argv[])
{
    
    try
    {
        MyServer server(8080); // give opportunity to user to choose port and address
        server.start();

        std::string buffer;

        FileHandler file("DataFile.txt");

   
        while (true) {
            printf("Accept\n");
            server.Accept();//Accepting a new connection
            printf("\nAccepted\n");
            file.WriteLine("=======================================================");


            while (true) {//Reading cycle
                buffer = server.Read();
                // Not the best way to fail read
                if(buffer == "0"){//Connection closed by the Client
                    break;
                }
                if(buffer == "-1"){
                    printf("\nReading Error\n");
                }else{
                    file.WriteLine(buffer);
                }
            }  
            std::string continue_;
            std::cout<<"\nIf you want to accept a new connection press Y\n";
            std::cin>>continue_;
            if(continue_ !="Y"){
                break;
            }


            
        }
        

    }
    catch(const std::invalid_argument& e)
    {
         std::cout <<"Error:"<< e.what() << '\n';
    }
    

    

    return 0;
}