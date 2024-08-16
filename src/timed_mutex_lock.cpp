#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

// There are timed mutex locks i.e. wait for "this" amount of time trying to get the lock if dont get it and duration ends then returns false

//if gets the lock before the duration elapses then yay! returns true

int dataval = 0;

std::timed_mutex m;

void increment( int i ){
    if(m.try_lock_for(std::chrono::seconds(1))){
        ++dataval;
        
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        cout<<"Thread "<< i << " entered \n";
        
        m.unlock();
    }
    else{
        cout<<"Thread "<< i <<" couldnt enter \n";
    }
}

int main()
{   
    std::thread t1(increment,1);
    std::thread t2(increment,2); //here these two try to enter critical sections, but who ever goes in first, the other thread waits for only 1 sec and since the in thread takes 3 sec the other thread wont get the lock in time and simply wont execute/remain suspended 

    t1.join();
    t2.join();

    cout<<"data: "<<dataval<<" \n";


    
    return 12;
}
