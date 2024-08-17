//locking multiple mutexes



//the std::lock(m1,m2,m3....) function locks all the mutexes in a deadlock free manner automatically, it does this by using a seq of calls to lock(),try_lock,  unlock()etc till all the mutexes are successfuly locked else it releases tries again
// it does above all automatically

//it is a blocking call, i.e. it blocks the execution of the process that has called it till this opearation successfully happens (in our case, the func successfully locks all mutexes)

//eg 1: 
//  Th1                     Th2
//  std::lock(m1,m2)        std::lock(m1,m2)
// Results in NO deadlock


//eg 2: 
//  Th1                     Th2
//  std::lock(m2,m1)        std::lock(m1,m2)
// Results in NO deadlock
//it works because of the std::lock(m1,m2,m3....) implementation 
//the implementaion tries all permutations and combinations of the order of locking of mutexes given in the arguments


//eg 3: 
//  Th1                           Th2
//  std::lock(m1,m2,m3,m4)        std::lock(m3,m4)
//                                std::lock(m1,m2)
// Results in NO deadlock


//eg 4: 
//  Th1                           Th2
//  std::lock(m1,m2)              std::lock(m3,m4)
//  std::lock(m3,m4)              std::lock(m1,m2)
// Results in YES deadlock


//they can only make the implementation this smart but mans stupidity has no bounds :)


#include<thread>
#include<mutex>
#include<iostream>

using namespace std;

std::mutex m1,m2,m3,m4;

void eg1(int t)
{   while(1){
        std::lock(m1,m2);
        cout<<"eg 1: locked m1,m2 successfully by "<< t <<"\n";
        m1.unlock();
        m2.unlock();
        break;
            }
}

void eg2_t1(int t)
{   while(1){
        std::lock(m1,m2);
        cout<<"eg 2: locked m1,m2 successfully by "<< t <<"\n";
        m1.unlock();
        m2.unlock();
        break;
            }
}

void eg2_t2(int t)
{   while(1){
        std::lock(m2,m1);
        cout<<"eg 2: locked m2,m1 successfully by "<< t <<"\n";
        m2.unlock();
        m1.unlock();
        break;
            }
}

void eg3_t1(int t)
{   while(1){
        std::lock(m1,m2);
        cout<<"eg 3: locked m1,m2 successfully by "<< t <<"\n";
        m1.unlock();
        m2.unlock();
        break;
            }
}

void eg3_t2(int t)
{   while(1){
        std::lock(m3,m4);
        std::lock(m1,m2);
        cout<<"eg 3: locked m3,m4 first then m1,m2 successfully by "<< t <<"\n";
        m3.unlock();
        m4.unlock();
        m1.unlock();
        m2.unlock();
        break;
            }
}

//nowdays the hardware is so fast that we may not get a deadlock despite coding it so, but have patience enough and it WLL happen

void eg4_t1(int t)
{   while(1){
        m1.lock();
        m2.lock();
        cout<<"eg 4: "<< t <<"\n";
        m1.unlock();
        m2.unlock();
            }
}

void eg4_t2(int t)
{   while(1){
        m2.lock();
        m1.lock();
        cout<<"eg 4: "<< t <<"\n";
        m2.unlock();
        m1.unlock();
            }
}

int main()
{
    //eg 1
    std::thread t1(eg1, 1);
    std::thread t2(eg1, 2);

    t1.join();
    t2.join();

cout<<"\n";
    
    //eg 2
    std::thread t3(eg2_t1,3);
    std::thread t4(eg2_t2,4);

    t3.join();
    t4.join();

cout<<"\n";
    
    std::thread t5(eg3_t1, 5);
    std::thread t6(eg3_t2, 6);

    t5.join();
    t6.join();

cout<<"\n";


    //eg 4 not doing because it dead locks and the programs just stays there, waiting

    //ohh... what the heck, might as well experience a deadlock on the CLI,

    // use ctrl + c to exit the C++ program

    std::thread t7(eg4_t1, 7);
    std::thread t8(eg4_t2, 8);

    t7.join();
    t8.join();

    return 323;
}