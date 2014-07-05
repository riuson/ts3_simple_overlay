#pragma once

#include "thread.h"

class SocketListener : private Thread
{
public:
    SocketListener(void);
    virtual ~SocketListener(void);

    void startListening(unsigned short port);
    void stopListening();

private:
    virtual unsigned thread_func(); 
    unsigned short mPort;
    unsigned listenClient(SOCKET socket);
};

