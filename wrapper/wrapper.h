#pragma once

// C language wrapper for folly SharedMutex

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct SharedMutex SharedMutex;

    SharedMutex* SharedMutexCreate();

    void SharedMutexDestroy(const SharedMutex* mutex);

    void SharedMutexLock(SharedMutex* mutex);

    void SharedMutexUnlock(SharedMutex* mutex);

    bool SharedMutexTryLock(SharedMutex* mutex);

    void SharedMutexLockShared(SharedMutex* mutex);

    void SharedMutexUnlockShared(SharedMutex* mutex);

    bool SharedMutexTryLockShared(SharedMutex* mutex);

#ifdef __cplusplus
}
#endif