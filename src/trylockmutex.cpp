#include<iostream>
#include<thread>
#include<mutex>

using namespace std;


std::mutex mymutex;

int counter = 0;

int counter_locked =0;

void increment_counter(){   
    for(int i=0;i<500000;++i)    {   
        if(mymutex.try_lock()) // this cause the thread to spin if it tries to access shared data but it is locked at that moment by another thread
            {++counter;
             mymutex.unlock();}
            //the try_lock() returns 0 if the mutex is locked and locks it if and returns 1 if it can/ gets the chance 
    }
    cout<<"\n";
}

void increment_counter_lock(){   
    for(int i=0;i<500000;++i)    {   
            {mymutex.lock();
             ++counter_locked;
             mymutex.unlock();}
            //the try_lock() returns 0 if the mutex is locked and locks it if and returns 1 if it can/ gets the chance 
    }
    cout<<"\n";
}


int main()
{   
    
    std:: thread t1(increment_counter);
    std:: thread t2(increment_counter);

    t1.join();
    t2.join();



    cout<<"counter val: "<< counter<<"\n"; // the val is always something wierd

    // this is because if the thread is unable to get the lock on on the shared variable, it acts as a //continue or //pass statement in the loop

    std:: thread t3(increment_counter_lock);
    std:: thread t4(increment_counter_lock);

    t3.join();
    t4.join();



    cout<<"counter val: "<< counter_locked<<"\n"; // this is exactly correct because of the lock() thing

    return 12;
}
