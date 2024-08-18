// std:: async

// it runs a function asynchronously (potentially in a new thread) and returns a std:: future that will hold the reault for us

// three policies to create a task:
    //std::launch::async
    //std::launch::deferred
    //std::launch::async | std::launch::async
    
    
    // How it works:
    // automatically createas a thread / picks from internal thread pool and a promise object for us
    
    //then passes the std::promise object to the thread function and returns the associated std::future object
    
    //when the passed argument functions exits, then its value will be set in the promise object

// we send a functor or lambda function as a callback to std::async, it works like a thread

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>

using namespace std;
using namespace std::chrono;

typedef long int ull;


ull findOddSum(ull start, ull end)
{   
    ull oddSum =0;
    cout<<"thread id of findOddSum: "<< std::this_thread::get_id() <<" \n";
    for(ull i=start;i<=end;i++)
    {
        if((i&1)==1)
        {oddSum += i;}
    }   
    return oddSum;
}


int main()
{
    ull start = 0 , end = 19000000;

    cout<<"thread id of main: "<< this_thread::get_id() <<" \n";
    cout<<"thread created if policy is std::launch::async \n";

    std::future<ull> oddSum = std::async(std::launch::deferred, findOddSum, start, end); // this deferred means start this thread whenever we call the promise object  // this is eager evaluation

    std::future<ull> oddSum2 = std::async(std::launch::async, findOddSum, start, end); // this is async i.e. it creates and executes the thread as it reaches this line

    cout<<"waiting for result \n";
    cout<<"Oddsum: "<< oddSum.get()<<" \n";

    cout<<"Oddsum2: "<< oddSum2.get()<<" \n";

    cout<<"completed \n";



    return 342;
}