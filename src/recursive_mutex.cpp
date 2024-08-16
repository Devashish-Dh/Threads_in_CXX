#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

// recursive mutexes; 
//they allow the same thread to lock one mutex multiple times

// if t1 locks recursive mutex m1 10 times then it need to unlock it 10 times also. No other thread will be able to lock till t1 is doing that 

//it should be avoided if possible because of large overhead

// it is simply mutex for recursive functions , like we did print in reverse order so the calling function last statement gets executed when we are popping the stack

std::recursive_mutex rmutex1;

int buffer = 0;

//the recursive program
void recursion(char c, int loopFor) {
    if(loopFor < 0) {
        return;
    }

    rmutex1.lock();
    cout<<"Thread: "<< c <<" "<<buffer++ <<" \n";
    --loopFor;
    recursion(c, loopFor);

    rmutex1.unlock();

}

int main()
{   
    std::thread t1(recursion, '0', 5);
    cout<<"\n";
    std::thread t2(recursion, '1', 5);

    t1.join();
    t2.join();


    //now the Loop way:

    for(int i=0; i<5; ++i){
        rmutex1.lock();
        std::cout<<" locked "<< i <<"\n";
    }
    for(int i=0; i<5; ++i){
        rmutex1.unlock();
        std::cout<<" unlocked "<< i <<"\n";
    }

    return 12;
}
