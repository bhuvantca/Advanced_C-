//Parallel algorithm - if we have 1 lakh vales in vector we can do parallel execution

#include<iostream>
#include<vector>
#include<algorithm>
#include<execution>
using namespace std;

int main()
{
    vector<int> v = {1,4,7,3,5};
    std::sort(std::execution::par,v.begin(),v.end());
    for(auto& itr : v)
    {
        std::cout << itr << std::endl;
    }
    return 0;
}
