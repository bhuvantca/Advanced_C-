//STD filesystem

#include<iostream>
#include<filesystem>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    fs::create_directory("temp");
    
    fs::copy_file("src.txt","det.txt", std::copy_options::overwrite_existing)
    for(auto &itr : fs::directory_iterator("temp"))
    {
        cout<<"name: "<<itr.path() <<endl;
    }
    return 0;
}
