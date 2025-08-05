#ifndef NEEDLE_H
#define NEEDLE_H

/*
This is a single header version of needle
The original needle project can be found here:
https://github.com/MasterToad7/Needle

To use this "independent header" simply define TIH_NEEDLE_DEFINITIONS
somewhere in the project then include the header

*VERY IMPORTANT* 
Make sure to only define TIH_NEEDLE_DEFINITIONS in one c file
*/

#ifdef _WIN32
    #include <Windows.h>
    #define OS_TYPE_WINDOWS
#elif __linux__
    #include <pthread.h>
    #define OS_TYPE_LINUX
#else
    #error "OS not detected, Needle only supports Windows and Linux for the time being."
#endif

typedef struct ndl_thread
{
    #ifdef OS_TYPE_WINDOWS

    HANDLE refThread;

    #elif defined(OS_TYPE_LINUX)

    pthread_t refThread;

    #endif
} ndl_thread_t;

// Preform a sanity check to make sure Needle is linked properly
void ndl_sanityCheck();

// Create a new thread
void ndl_createThread(ndl_thread_t* addrThread, void*(*startRoutine)(void*), void* arg);

// Exit the current thread
void ndl_exitThread();

// Wait for another thread to finish
void ndl_joinThread(ndl_thread_t* addrThread);

#ifdef TIH_NEEDLE_DEFINITIONS

void ndl_sanityCheck()
{
    #ifdef OS_TYPE_WINDOWS

    printf("Needle Is Linked Properly For Windows\n");

    #elif defined(OS_TYPE_LINUX)

    printf("Needle Is Linked Properly For Linux\n");

    #endif
}

void ndl_createThread(ndl_thread_t* addrThread, void*(*startRoutine)(void*), void* arg)
{
    #ifdef OS_TYPE_WINDOWS

    DWORD threadId;
    addrThread->refThread = CreateThread(NULL,0,startRoutine,arg,0,&threadId);

    #elif defined(OS_TYPE_LINUX)

    pthread_create(&addrThread->refThread, NULL, startRoutine, arg);

    #endif
}

void ndl_exitThread()
{
    #ifdef OS_TYPE_WINDOWS

    ExitThread(NULL);

    #elif defined(OS_TYPE_LINUX)

    pthread_exit(NULL);

    #endif
}

void ndl_joinThread(ndl_thread_t* addrThread)
{
    #ifdef OS_TYPE_WINDOWS

    WaitForSingleObject(addrThread->refThread,INFINITE);
    
    #elif defined(OS_TYPE_LINUX)

    pthread_join(addrThread->refThread, NULL);

    #endif
}

#endif
#endif