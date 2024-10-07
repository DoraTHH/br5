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

    // Skapa klientens socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    printf("Socket created.\n");

    // Definiera serverns adress
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9001); // Samma port som servern
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Ansluter till localhost

    // Anslut till servern
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        printf("Connection failed. Error Code: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    printf("Connected to server.\n");

    // Ta emot meddelande från servern
    char buffer[1024] = {0};
    int valread = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (valread > 0) {
        printf("Message from server: %s\n", buffer);
    } else {
        printf("Failed to receive message from server.\n");
    }

    // Stäng socket och rensa upp Winsock
    closesocket(clientSocket);
    WSACleanup();

    getchar();

    return 0;
}
