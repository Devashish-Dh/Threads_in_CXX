# Threads in C++

Small demos for C++ threading: creation, join/detach, mutexes, lock guards, condition variables, futures, and `std::async`.

Executable targets are listed **in teaching order** in [`CMakeLists.txt`](CMakeLists.txt):

1. `single_thread_demo`
2. `multiple_threads_demo`
3. `ways_to_create_threads`
4. `join_detach_and_joinable`
5. `mutexes` → `trylockmutex` → `trylocking_multiple_mutexes` → `timed_mutex_lock` → `recursive_mutex`
6. `lock_guards` → `unique_lock` → `conditional_vars` → `lock_multiple_mutexes`
7. `future_and_promise` → `async`

## Build

```bash
cmake -S . -B build
cmake --build build
```

Sources are under [`src/`](src/).
