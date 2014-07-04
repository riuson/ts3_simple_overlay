#pragma once

#include <wchar.h>
#include <Windows.h>

class Thread
{
public:
    Thread(void);
    ~Thread(void);

    void start();
    void stop();

protected:
    virtual unsigned thread_func();
    HANDLE mTerminateEvent;

private:
    HANDLE mMainThread;
    static unsigned __stdcall thread_entry_point(LPVOID param);
};
