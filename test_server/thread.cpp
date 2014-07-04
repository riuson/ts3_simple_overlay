#include "StdAfx.h"
#include "thread.h"
#include <WinDef.h>
#include <WinBase.h>
#include <process.h>

Thread::Thread(void)
{
    this->mMainThread = NULL;
    this->mTerminateEvent = CreateEvent(NULL, TRUE, FALSE, L"Thread Need Stop Event");
    ResetEvent(this->mTerminateEvent);
}


Thread::~Thread(void)
{
    this->stop();
}

void Thread::start()
{
    unsigned threadId;

    //this->mMainThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread::thread_entry_point(this), this, 0, NULL);
    
    this->mMainThread = (HANDLE)_beginthreadex(
        NULL, // security
        0,    // stack size
        Thread::thread_entry_point,// entry-point-function
        this,           // arg list holding the "this" pointer
        CREATE_SUSPENDED, // so we can later call ResumeThread()
        &threadId);
    
    ResetEvent(this->mTerminateEvent);
    ResumeThread(this->mMainThread);
}

void Thread::stop()
{
    if (this->mMainThread != NULL) {
        SetEvent(this->mTerminateEvent);

        WaitForSingleObject(this->mMainThread, INFINITE );

        this->mMainThread = NULL;
    }
}

unsigned Thread::thread_func()
{
    while (true) {
        unsigned waitResult = WaitForSingleObject(this->mTerminateEvent, 1000);

        if (waitResult == WAIT_OBJECT_0) {
            // thread stopped
            break;
        } else if(waitResult == WAIT_TIMEOUT) {
            // thread running
        } else {
            // error
            return 1;
        }
    }

    return 0;
}

unsigned __stdcall Thread::thread_entry_point(LPVOID param)
{
    Thread* obj = static_cast<Thread*>(param);

    unsigned result = obj->thread_func();    // now call the true entry-point-function

    // A thread terminates automatically if it completes execution,
    // or it can terminate itself with a call to _endthread().

    // the thread exit code
	return result;
}
