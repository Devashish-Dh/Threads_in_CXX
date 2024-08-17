#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

using namespace std;

//the condition variable is used to "notify" threads about stuff 
//used for thread synchronization
//a thread does something and can trigger a waiting thread i.e. notify() it

//two ways 
//notify_one()
//notify_all()

//a mutex is needed to use the condition_variable

// a thread can wait on a condition by:

/*
    acquire a mutex lock and use the std::unique_lock<std::mutex> lock(m)

    execute wait, wait_for, wait_until stuff

    when the condition variable is notified, the mutex is automatically acquired the thread should then check the condition to make sure it was not a spurious wake up

 */




std::condition_variable cv;

std::mutex m;

long balance = 0;

void increment(int money){
    std::lock_guard<mutex> lg(m);
    balance += 500;
    cout<<"added funds \n";

    cv.notify_one();// whoever is waiting on this condition_variable,wake up and run!
}

void decrement(int money){
    std::unique_lock<mutex> ul(m); //the unique lock has locked() the mutex here but

    cv.wait(ul, [] { return (balance != 0) ? true : false; });// here the thread unlocks/releases the mutex and waits on the condtition to be true, The moment the condition_varible is notified() by some other thread, this thread restarts from its top and carries on with the execution i.e. lock(),check_condition, if ture do the rest)

    if(balance >= money){
        balance-=money;
        cout<<"decremented amt "<< money <<"\n";}
    else{
        cout<<"not enough funds \n";
        cout<<"balance: "<< balance <<"\n";
        cout<<"trying to decrement: "<< money <<"\n";
    }
    
}

int main()
{   
    std::thread t1(decrement, 500);
    std::thread t2(increment,1000);

    t1.join();
    t2.join();

    return 43;
}