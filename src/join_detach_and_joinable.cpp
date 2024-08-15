#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

// learning about join() detach() and joinable() thread

//join:
    //the parent(main) process waits at this point for the thread to finish executing

    void run()
    {
        cout<<"\nthread running \n"<<endl;
        std::this_thread::sleep_for(chrono::seconds(4));
    }

int main()
{   
    cout<<"this is main "<<endl;

    std::thread t1(run);
    t1.join();//main waits for t1 to end at this point of code

    cout<<"this is main again "<<endl;


    // if we join() the same thread again it ducks up the main() process

    //so we guard it using the joinable() : tells if a thread can be joine()ed

    cout<<"this is main\n"<<endl;

    std::thread t2(run);
    cout<<"t2 is joinable()? "<<t2.joinable();
    if(t2.joinable())t2.join(); // always use this guard of joinable()
    cout<<"\nthis is main again \n"<<endl;


    // the detach() is used to detach the parent from the child thread

    cout<<"this is main\n"<<endl;

    std::thread t3(run);
    t3.detach();
    cout<<"\nthis is main which did not wait for the t3 to complete its execution before running on to the next lines... \n"<<endl;

    //detach means that main() wont care about the t3s execution at all and t3s output may never be seen because if main() reaches its end then os will suspend t3

    //double detach does duck up the main() too

    return 234;
}