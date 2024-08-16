#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

// recursive mutexes; 
//they allow the same thread to lock one mutex multiple times

// if t1 locks recursive mutex m1 10 times then it need to unlock it 10 times also. No other thread will be able to lock till t1 is doing that 

//it should be avoided if possible because of large overhead


int main()
{   
   
    return 12;
}
