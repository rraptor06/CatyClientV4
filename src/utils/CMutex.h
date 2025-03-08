#pragma once

#include <malloc.h>

#include <coreinit/mutex.h>

class CMutex {
public:
    CMutex() {
        pMutex = (OSMutex*)malloc(sizeof(OSMutex));
        if(!pMutex) {
            return;
        }

        OSInitMutex(pMutex);
    }

    virtual ~CMutex() {
        if(pMutex) {
            free(pMutex);
        }
    }

    void lock(void) {
        if(pMutex) {
            OSLockMutex(pMutex);
        }
    }

    void unlock(void) {
        if(pMutex) {
            OSUnlockMutex(pMutex);
        }
    }

    BOOL tryLock(void) {
        if(!pMutex) {
            return false;
        }

        return OSTryLockMutex(pMutex) != 0;
    }
    
private:
    OSMutex *pMutex;
};

class CMutexLock {
public:
    CMutexLock() {
        mutex.lock();
    }

    virtual ~CMutexLock() {
        mutex.unlock();
    }

private:
    CMutex mutex;
};