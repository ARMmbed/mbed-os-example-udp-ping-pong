# Mbed OS - UDP ping-pong with node.js

**Looking for TCP? See [mbed-tcp-ping-pong](https://github.com/janjongboom/mbed-tcp-ping-pong).**

Tested on ODIN-W2 EVK, but should work on every Mbed OS 5 device that implements the [Network Sockets API](https://os.mbed.com/docs/v5.6/reference/network-socket.html).

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

1. Open `mbed_app.json` and set your connectivity method and WiFi credentials.
1. Open `main.cpp` and set the IP (or hostname) of the server.
1. Compile and flash on the device.

## What it does

The Mbed device will set up a UDP socket to the server, and will send 'ping' the server. The server will respond with 'pong'.
