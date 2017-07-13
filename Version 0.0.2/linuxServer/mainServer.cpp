//
// Created by 李欣 on 2017/7/13.
//

#include "mainServer.h"

mainServer::mainServer() {
    cout << "\033[1;32m" << "[*] Establishing Server..." << "\033[0m" << endl;
    setPort();
    establishServer();
}

void mainServer::setPort() {
    int port;
    cout << "\033[1;32m" << "[*] Set the target port: " << "\033[0m" << "\033[1;36m";
    cin >> port;
    cout << "\033[0m";
    _sockServer.setPort(port);
}

void mainServer::establishServer() {
    _sockServer.bindSocket();
    _sockServer.listenClient();
    cout << "\033[1;32m" << "[+] Server Established" << "\033[0m" << endl;
    _sockServer.acceptClient();
}

void mainServer::clientMonitor() {
    char buffer[100];
    char dutyFlag[100] = "[*] Reporting For Duty";
    char standbyFlag[100] = "[+] Standby";
    char execFlag[100] = "[-] Suicide";
    _sockServer.threadSend(standbyFlag);
    while (_sockServer.threadReceive(buffer)) {
//    while (true) {
//        _sockServer.threadReceive(buffer);
//        /// DebugFlag!!! To be annotated
//        std::cout << "\033[1;32m" << "[*] Respond: " << "\033[0m" << "\033[1;36m" << buffer << "\033[0m"
//                  << std::endl;
//        /// DebugFlag!!! To be annotated
        if (strcmp(buffer, dutyFlag) != 0) {
            _sockServer.threadSend(execFlag);
        }
        _sockServer.threadSend(standbyFlag);
//        /// DebugFlag!!! To be annotated
//        std::cout << "\033[1;32m" << "[*] Sent: " << "\033[0m" << "\033[1;36m" << dutyFlag << "\033[0m"
//                  << std::endl;
//        /// DebugFlag!!! To be annotated
    }
}