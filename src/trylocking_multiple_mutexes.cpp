#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

//understand this code it is a very good exercise

int X =0; 
int Y =0;

std::mutex m1, m2;
// to simlutaneously lock multiple objects (mutexes) 
// the argumnents (mutexes) are indexed and the func tries to all of them at the same time.

// if success it returns -1

//if failed on Some mutex it returns the index of that mutex

// remember trylock() it passes/continues in case it cant get a lock()

// if you want to spinlock the thread then use lock() simple

// if not able to lock all together then it will release all the locks

void sleepThread(int seconds){ std::this_thread::sleep_for(std::chrono::seconds(seconds)); }

void incrementXY(int & XorY, std::mutex & m, const char* desc)
{
    for (int i=0;i<5;++i){
        m.lock();
        ++XorY;
        cout<< desc << " = "<< XorY <<"\n";
        m.unlock();
        sleepThread(2);
    }
}

void consumeXY()
{
    int userCount = 5;
    int XplusY =0;
    
    while(1)
    {
        int lockResult = std::try_lock(m1,m2);
        
        if(lockResult == -1){
            if(X!=0 && Y!=0){
                --userCount;
                XplusY += X+Y;
                X=0;
                Y=0;
                cout<<"XplusY = "<< XplusY <<" \n";
            }
        m1.unlock();
        m2.unlock();

        if(userCount ==0 ){ break; }
        }
    }
}


int main()
{   
    std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X");
    std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y");

    //this simulates the simple Reader Writer problem the t1,t2 produce X and Y repectively
    
    //t3 acts as the consumer
    //t3 can only consume by locking t1,t2 then checking the X and Y values 

    //if criteria met, it consumes them else it simply loops around

    std::thread t3(consumeXY);


    t1.join();
    t2.join();
    t3.join();
    
    return 12;
}
