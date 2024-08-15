#include<iostream>
#include<thread>
#include<mutex>

using namespace std;


//Mutex = mutual exclusion
std::mutex mymutex;
//Race Condition = happens when two or more threads try to access the same data to MODIFY it, it can cause inconsistency and unknown behaviors at runtime, 

//so shared data must be protected using mutex locks (Os)

int mydata = 0;

void increment()
{   
    cout<<"\ncurrent val "<<mydata<<" \n";
    ++mydata; // this is critical section
    cout<<"\nincremented data! \n";
}

void increment_mutex()
{   mymutex.lock(); // whoever reaches this code first gets a lock on the mymutex and due to it the other thread will get blocked
    cout<<"\ncurrent val "<<mydata<<" \n";
    ++mydata; // this is critical section
    mymutex.unlock();
    cout<<"\nincremented data! \n";
}

int main()
{   
    std::thread t1(increment);
    std::thread t2(increment);
    // race condition happens when t1 and t2 both read the same value of data, then they write the val into that variable and instead of incrementing twice it only increments by one

    t1.join();
    t2.join();

    cout<<"\ncurrent val "<<mydata<<" \n";
    
    // better way to do it would be semaphore but we are simply using mutex locks


    std::thread t3(increment_mutex);
    std::thread t4(increment_mutex);
    // race condition happens when t1 and t2 both read the same value of data, then they write the val into that variable and instead of incrementing twice it only increments by one

    t3.join();
    t4.join();

    cout<<"\ncurrent val "<<mydata<<" \n";


    return 12;
}
