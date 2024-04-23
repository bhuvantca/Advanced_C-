//STD FUTURE & STD ASYNC

#include<iostream>
#include<future>
using namespace std;

int add(int x, int y)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    int out = x + y;
    return out;
}

int main()
{
    future<int> ft=std::async(add,5,6);
    
    //tasks
    int sum = ft.get();
    cout<<"result is: "<<sum;
    return 0;
}

