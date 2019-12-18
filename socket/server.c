#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main()
{
    char server_message[256] = "You have reached the server!";
    int server_socket;
    server_socket = socket(AF_INET, sOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(server_soket, (struct sockaddr *)&server_address, sizeof(server_address));

    // start listening for the connection,
    // 1) Server Socket.
    // 2) back log : how many connections can be waiting.
    listen(server_socket, 5);

    int client_socket;
    // 2) Structure : if you pass the structure, then you can figure out where the data and ip is coming from
    // 3) the size of the structure.
    client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, server_message, sizeof(server_message));

    close(server_socket);
}