// the class unique_lock is a mutex wonership wrapper


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;

int buffer =0;



//example 1

void task(const char* threadNumber, int loopFor) {
    std::unique_lock<mutex> lock(m1); // dont have to unlock ourself it happens automatically
    for(int i=0; i<loopFor; ++i){
        ++buffer;
        cout<< threadNumber <<" "<< buffer <<"\n";
    }
    cout<<"\n";
}


//example 2

void task_defer(const char* threadNumber, int loopFor) {
    std::unique_lock<mutex> deferredlock(m1,std::defer_lock); // the defer means we will lock it some other time ourself explicitly (wesimply own it-- whatever that means)

    deferredlock.lock(); // like here
    for(int i=0; i<loopFor; ++i){
        ++buffer;
        cout<< threadNumber <<" "<< buffer <<"\n";
    }
    cout<<"\n";
}



int main()
{   
    //example 1
    thread t1(task, "T1", 5);
    thread t2(task, "T2", 5);

    t1.join();
    t2.join();


    //example 2
    thread t3(task, "T3", 5);
    thread t4(task, "T4", 5);

    t3.join();
    t4.join();

    return 34;
}