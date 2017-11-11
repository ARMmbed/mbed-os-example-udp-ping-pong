# Mbed OS - TCP ping-pong with node.js

Tested on ODIN-W2 EVK.

Get both devices on the same WiFi network, or host the server on a publicly available hostname.

## Setting up the server

1. Install a recent version of node.js.
1. Open a terminal.
1. Navigate to the `server-in-node` directory.
1. Run:

    ```
    $ node server.js
    ```

1. Note down the IP address of the WiFi interface.

## Setting up the client

1. Open `main.cpp` and set the IP (or hostname) of the server.
1. Compile and flash on the device.
