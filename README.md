# folly_shared_mutex

This is the `shared_mutex` implementation from [folly](https://github.com/facebook/folly) library.

## Build

```bash
git clone https://github.com/26F-Studio/folly_shared_mutex.git
cd folly_shared_mutex
mkdir build
cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" -S . -B build
cmake --build build --target folly_shared_mutex
```