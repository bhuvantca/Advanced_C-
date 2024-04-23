//Structure Binding

#include<iostream>
using namespace std;
struct Person
{
  int empId;
  string employeeName;
  int mobile;
};

int main()
{
    Person p{12,"MDU",900000000};
    auto [id, name, mobile] = p;
    cout<<"ID: "<<id<<" Name: "<<name<<std::endl;
    return 0;
}
