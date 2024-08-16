#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

// how to use std::lock_guard <mutex> 
//it is a wrapper that is used to lock and unlock mutex on the basis of "scope"

//so we dont have to remember to always .unlock() the mutex

std::mutex m1;

int buffer = 0;

void task(const char* threadNumber, int loopFor){
    m1.lock();
    for(int i=0; i<loopFor; ++i){
        ++buffer;
        cout<<threadNumber<<" "<<buffer<<" \n";
    }
    cout<<"\n";
    m1.unlock();
}

void task_lock_guard(const char* threadNumber, int loopFor){
    
    std::lock_guard<mutex> lock(m1); //this acquires and the lock and stays till the function ends, then automatically unlocks

    for(int i=0; i<loopFor; ++i){
        ++buffer;
        cout<<threadNumber<<" "<<buffer<<" \n";
    }
    cout<<"\n";
}

int main()
{

    thread t1(task,"T1",5);
    thread t2(task,"T2",5);

    t1.join();
    t2.join();

    thread t3(task,"T3",5);
    thread t4(task,"T4",5);

    t3.join();
    t4.join();

    return 43;
}