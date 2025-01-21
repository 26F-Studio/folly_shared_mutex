#include <wrapper/wrapper.h>

#include <folly/SharedMutex.h>

struct SharedMutex {
    folly::SharedMutex mutex;
};

SharedMutex* SharedMutexCreate() {
    return new SharedMutex();
}

void SharedMutexDestroy(const SharedMutex* mutex) {
    delete mutex;
}

void SharedMutexLock(SharedMutex* mutex) {
    mutex->mutex.lock();
}

void SharedMutexUnlock(SharedMutex* mutex) {
    mutex->mutex.unlock();
}

bool SharedMutexTryLock(SharedMutex* mutex) {
    return mutex->mutex.try_lock();
}

void SharedMutexLockShared(SharedMutex* mutex) {
    mutex->mutex.lock_shared();
}

void SharedMutexUnlockShared(SharedMutex* mutex) {
    mutex->mutex.unlock_shared();
}

bool SharedMutexTryLockShared(SharedMutex* mutex) {
    return mutex->mutex.try_lock_shared();
}