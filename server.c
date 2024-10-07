#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

// Länkning av Winsock-biblioteket
#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initiera Winsock
    WSADATA wsa;
    printf("Initialising Winsock...\n");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Winsock initialized.\n");

    // Skapa en socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    printf("Socket created.\n");

    // Definiera serverns adress
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY; // Lokal maskin
    serverAddress.sin_port = htons(9001);       // Port 9001

    // Binda socket till IP och port
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    printf("Bind successful.\n");

    // Lyssna efter inkommande anslutningar
    if (listen(serverSocket, 3) == SOCKET_ERROR) {
        printf("Listen failed. Error Code: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    printf("Listening for incoming connections...\n");

    // Acceptera en inkommande anslutning
    int clientSize = sizeof(struct sockaddr_in);
    struct sockaddr_in clientAddress;
    SOCKET clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientSize);
    if (clientSocket == INVALID_SOCKET) {
        printf("Accept failed. Error Code: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    printf("Client connected.\n");

    // Skicka ett meddelande till klienten
    char *message = "Hello Client, welcome to the server!";
    send(clientSocket, message, strlen(message), 0);

    // Stäng klient- och serversocket
    closesocket(clientSocket);
    closesocket(serverSocket);

    // Rensa upp Winsock
    WSACleanup();

    getchar();

    return 0;
}
