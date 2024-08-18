CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(Threads_in_CXX
        VERSION 1.0
        DESCRIPTION "Description" 
        LANGUAGES CXX       
)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include) # for header files if any
SET(SOURCES ${CMAKE_SOURCE_DIR}/src)# source files of the project







ADD_EXECUTABLE(single_thread_demo ${SOURCES}/single_thread_demo.cpp)

ADD_EXECUTABLE(multiple_threads_demo ${SOURCES}/multiple_threads_demo.cpp)

ADD_EXECUTABLE(ways_to_create_threads ${SOURCES}/ways_to_create_threads.cpp)

ADD_EXECUTABLE(join_detach_and_joinable ${SOURCES}/join_detach_and_joinable.cpp)

ADD_EXECUTABLE(mutexes ${SOURCES}/mutexes.cpp)

ADD_EXECUTABLE(trylockmutex ${SOURCES}/trylockmutex.cpp)

ADD_EXECUTABLE(trylocking_multiple_mutexes ${SOURCES}/trylocking_multiple_mutexes.cpp)

ADD_EXECUTABLE(timed_mutex_lock ${SOURCES}/timed_mutex_lock.cpp)

ADD_EXECUTABLE(recursive_mutex ${SOURCES}/recursive_mutex.cpp)

ADD_EXECUTABLE(lock_guards ${SOURCES}/lock_guards.cpp)

ADD_EXECUTABLE(unique_lock ${SOURCES}/unique_lock.cpp)

ADD_EXECUTABLE(conditional_vars ${SOURCES}/conditional_vars.cpp)

ADD_EXECUTABLE(lock_multiple_mutexes ${SOURCES}/lock_multiple_mutexes.cpp)

ADD_EXECUTABLE(future_and_promise ${SOURCES}/future_and_promise.cpp)

ADD_EXECUTABLE(async ${SOURCES}/async.cpp)

ADD_EXECUTABLE(async ${SOURCES}/async.cpp)



















