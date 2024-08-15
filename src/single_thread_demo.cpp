#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum;
ull evenSum;



void findEvenSum(ull start, ull end)
{
    for(ull i = start; i<= end; i++)
    {
        if ((i&1)==0)
        {oddSum += 1;}
    }
}

void findOddSum(ull start, ull end)
{   
    for(ull i=start;i<=end;i++)
    {
        if((i&1)==1)
        {evenSum += 1;}
    }   
}

int main()
{   
    ull start = 0; ull end = 1900000000;
    
    auto startTime = high_resolution_clock::now();
    
    findOddSum(start,end);
    findEvenSum(start,end);

    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast <microseconds> (endTime - startTime);

    cout<<"odd sum = "<<oddSum<<endl;
    cout<<"even sum = "<<evenSum<<endl;

    cout<<"time taken = "<< duration.count()/1000000 <<" sec "<< endl;


    return 12;
}
