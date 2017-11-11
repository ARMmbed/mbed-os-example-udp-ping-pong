#include "mbed.h"
#include "easy-connect.h"

#define HOST_IP			"192.168.43.69"
#define HOST_PORT		1884

UDPSocket socket;

// Receive data from the server
void receiveUDP() {
    // Allocate 2K of data
    char* data = (char*)malloc(2048);
    while (1) {
        // recvfrom blocks until there is data
        nsapi_size_or_error_t size = socket.recvfrom(NULL, data, 2048);
        if (size <= 0) {
            if (size == NSAPI_ERROR_WOULD_BLOCK) continue; // OK... this is a non-blocking socket and there's no data on the line

            printf("Error while receiving data from UDP socket (%d)\n", size);
            continue;
        }

        // turn into valid C string
        data[size] = '\0';

        printf("Received %d bytes from UDP socket (%s)\n", size, data);
    }
}

int main() {
    printf("Welcome to Mbed UDP ping pong\n");

    NetworkInterface *network = easy_connect(true);
    if (!network) {
        printf("Failed to get a network connection... See serial output.\n");
        return 1;
    }

    // Open a UDP socket
    nsapi_error_t rt = socket.open(network);
    if (rt != NSAPI_ERROR_OK) {
        printf("Could not open UDP Socket (%d)\n", rt);
        return 1;
    }

    socket.set_blocking(false);

    Thread socket_thread;
    socket_thread.start(&receiveUDP);

    while (1) {
        char buffer[] = "ping";
        socket.sendto(HOST_IP, HOST_PORT, buffer, strlen(buffer));

        printf("Sent %d bytes over UDP socket (%s)\n", strlen(buffer), buffer);
        wait_ms(2000);
    }

    wait_ms(osWaitForever);
}
