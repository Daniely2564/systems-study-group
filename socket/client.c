#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h> // store address information

int main()
{
    // TCP Client.

    // create a socket.
    int network_socket;
    // socket(DOMAIN_OF_THE_SOCKET, SOCK_STREAMS)
    // 2) SOCK_STREAM : Type of Socket. Using TCP Socket here.
    // 3) Protocal : Telling that we are just using default socket.
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // we need to connect to another side...
    // In order to achieve this we need to use connect().
    // we need to specify the address to connect to.
    // This is where netinet/in.h comes into play.
    // it contains a structure that we can define few fields on, such as address and port.

    // specify an address for the socket.
    struct sockadd_in server_address;
    server_address.sin_family = AF_INET;   // The family of address, what type of address it is working with.
    server_address.sin_port = htons(8080); // This htons converts integer to understandable port for sin_port.
    // This is where you want to put actual address, but since we are connecting to the 0.0.0.0, local server, we can just input short cut of the address
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Now we are ready to connect
    // connect(socket, address of server_address struct, size of server_address structure).
    int connection_status = connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    // connection_status 0 => connected
    // connection_status -1 => connection failed.
    if (connection_status == -1)
    {
        printf("There was an error making a connection to the remote socket\n\n");
        return -1;
    }
    // if we have successfully connected we will either receive or send data.
    // recv(:receive)(network_socket, receiving_message, buffer_size)
    // 2) receiving_messsage : string address to store the message.
    // 3) buffer_size : size of the bytes to read.
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // since we received the data, we will print out the data we get back.
    printf("The message from the server : %s\n", server_response);

    // after all finished we will close the socket.
    close(network_socket);

    return 0;
}