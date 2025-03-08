#pragma once

#include <malloc.h>
#include <unistd.h>
#include <string>

#include <coreinit/systeminfo.h>
#include <coreinit/thread.h>

class CThread {
public:
    typedef void (*Callback)(CThread *thread, void *arg);

    explicit CThread(int32_t iAttr, int32_t iPriority = 16, int32_t iStackSize = 0x8000,
                     CThread::Callback callback = nullptr, void *callbackArg = nullptr, const std::string &threadName = "")
                     : pThread(nullptr), pThreadStack(nullptr), pCallback(callback),
                       pCallbackArg(callbackArg)
    {
        iAttributes = iAttr;
        pThread = (OSThread *) memalign(8, sizeof(OSThread));
        pThreadStack = (uint8_t *) memalign(0x20, iStackSize);
        if (pThread && pThreadStack) {
            OSCreateThread(pThread, &CThread::threadCallback, 1, (char *) this, pThreadStack + iStackSize, iStackSize, iPriority, iAttributes);
            pThreadName = threadName;
            OSSetThreadName(pThread, pThreadName.c_str());
        }
    }

    ~CThread() {
        shutdownThread();
    }

    static CThread *create(CThread::Callback callback, void *callbackArg, int32_t iAttr = eAttributeNone, int32_t iPriority = 16, int32_t iStackSize = 0x8000) {
        return (new CThread(iAttr, iPriority, iStackSize, callback, callbackArg));
    }

    [[nodiscard]] virtual void *getThread() const {
        return pThread;
    }

    virtual void executeThread() {
        if (pCallback) {
            pCallback(this, pCallbackArg);
        }
    }

    virtual void suspendThread() {
        if (isThreadSuspended()) {
            return;
        }

        if (pThread) {
            OSSuspendThread(pThread);
        }
    }

    bool resumeThread() {
        if (!isThreadSuspended()) {
            return false;
        }

        if (pThread) { 
            OSResumeThread(pThread); 
            
            return true;    
        }

        return false;
    }

    virtual void setThreadPriority(int prio) {
        if (pThread) {
            OSSetThreadPriority(pThread, prio);
        }
    }

    [[nodiscard]] virtual BOOL isThreadSuspended() const {
        if (pThread) {
            return OSIsThreadSuspended(pThread);
        }

        return false;
    }

    [[nodiscard]] virtual BOOL isThreadTerminated() const {
        if (pThread) {
            return OSIsThreadTerminated(pThread);
        }

        return false;
    }

    [[nodiscard]] virtual BOOL isThreadRunning() const {
        return !isThreadSuspended() && !isThreadRunning();
    }

    void shutdownThread() {
        if (pThread && !(iAttributes & eAttributeDetach)) {
            if (isThreadSuspended()) {
                resumeThread();
            }

            OSJoinThread(pThread, nullptr);
        }

        if (pThreadStack) {
            free(pThreadStack);
        }

        if (pThread) {
            free(pThread);
        }

        pThread      = nullptr;
        pThreadStack = nullptr;
    }

    enum eCThreadAttributes {
        eAttributeNone      = 0x07,
        eAttributeAffCore0  = 0x01,
        eAttributeAffCore1  = 0x02,
        eAttributeAffCore2  = 0x04,
        eAttributeDetach    = 0x08,
        eAttributePinnedAff = 0x10
    };

private:
    static int threadCallback(int argc, const char **argv) {
        ((CThread *)argv)->executeThread();
        return 0;
    }

    int iAttributes;
    OSThread *pThread;
    uint8_t *pThreadStack;
    Callback pCallback;
    void *pCallbackArg;
    std::string pThreadName;
};