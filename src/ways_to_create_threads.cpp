#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;

// the different ways we can create threads

//1, Using a function pointer:
void fun(int x)
{
    while(x > 0)
    {
        cout<<x<<" ";
        x-=1;
    }
    cout<<"\n ended a function pointer thread \n \n";    
}



//3, using a functor i.e. a function object

class Base {
    public:
    void operator()(int x)
    {
        while(x>0)
        {
         cout<<x<<" ";
        x-=1;
        }
    cout<<"\n ended a functor thread \n \n";
    }

//4, using a non static (to class) member function
    void runner(int x)
    {
        while(x>0)
        {
         cout<<x<<" ";
        x-=1;
        }
    cout<<"\n ended a non static member function thread \n \n";
    }

//5, using a static (to class) function
    static void runner2(int x)
    {
        while(x>0)
        {
         cout<<x<<" ";
        x-=1;
        }
    cout<<"\n ended a static function thread \n \n";
    }
};





int main()
{   
    std::thread t1(fun,10); // order of creation is not guaranteed either and writing the code in whichever order does not mean they will end in that order only

    t1.join(); // this was created using a function pointer

//----------------------------------------------------------------------

    //2, Using a lambda expression:
    auto fun = [](int x){
        while (x>0)
        {
            cout<< x <<" ";
            x--;
        }
        cout<<"\n ended a lambda expression thread \n \n";
    };   

    //we can directly "inject" the lambda 
    std::thread t2 (fun, 11);
    t2.join();


    //3 the functor way:
    std::thread t3((Base()),12);
    t3.join();

    //4 the non static member function way:
    Base b;
    std::thread t4(&Base::runner,&b,13); // we are giving the address of that func and the object which we want to use
    t4.join();

    //5 the static function way:
    std::thread t5(&Base::runner2,14);
    t5.join();

    return 12;
}