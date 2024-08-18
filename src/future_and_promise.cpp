//std::future and std::promise

//these are used for inter thread communication

// promise is used to set values and exceptions

// future is used to:
    // get values from promise
    // ask promise if a value is available
    // wait for the promise


#include<iostream>
#include<thread>
#include<algorithm>
#include<future>

using namespace std;

using namespace std::chrono;

typedef long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
    
    ull oddSum = 0;

    for(ull i = start; i <= end; ++i)
    {
        if(i & 1){ oddSum += 1; }
    }

    OddSumPromise.set_value(oddSum);// the thread updates the promise value to whatever it wants when it is done executing.
}

int main()
{
    ull starter = 0; ull ender = 1900000000;

    std::promise <ull> OddSum; // step 1 : create a promise object

    std::future <ull> OddFuture = OddSum.get_future(); // step 2 : creating a future object that will get the value from the promise object 

    cout<<"creating thread \n";

    std::thread t1(findOdd, std::move(OddSum), starter, ender);// the promise is passed as a prarmeter to the thread and ... see func def

    cout<<"waiting for the result \n"; // notice we did not join() the thread here, OddFuture.get() waits on the thread and only proceeds when a value is updated.

    cout<<"OddSum: "<< OddFuture.get() <<"\n";// how does it know that the value has been updated or not? done by internal implementation

    cout<<"completed job \n";

    t1.join();

    return 43;
}