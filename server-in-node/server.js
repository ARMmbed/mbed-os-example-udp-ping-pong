'use strict';

const dgram = require('dgram');
const udpServer = dgram.createSocket('udp4');
const printIps = require('./get_ips');

// UDP Server
udpServer.on('listening', () => {
    printIps();

    var address = udpServer.address();
    console.log('UDP Server is up and running at port', address.port);
});

let messages = {};

udpServer.on('message', (message, remote) => {
    console.log('UDP Receive', remote.address, remote.port, message.toString('ascii'));

    if (message.toString('ascii') === 'ping') {
        udpServer.send('pong', remote.port, remote.address);
    }
});

udpServer.bind(1884, '0.0.0.0');
