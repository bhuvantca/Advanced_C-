#include<iostream>
using namespace std;

template<typename T>
class sharedpointer
{
  private:
  T* content;
  int* counter;
  
  void increment_counter()
  {
      if(counter)
      {
      (*counter)++;
      }
  }
  
  void decreament_counter()
  {
  if(counter)
  {
      (*counter)--;
      if((*counter)==0)
      {
          if(content)
          {
              delete content;
              delete counter;
              content = nullptr;
              counter = nullptr;
          }
      }
  }
  }
  public:
  //default , param ctor
  sharedpointer(T* ptr = nullptr) : content(ptr), counter(new int(1))
  {
      cout<<"constructor id called"<<endl;
  }
  //copy ctor
  sharedpointer<T>(const sharedpointer<T>& ptr)
  {
      content = ptr.content;
      counter = ptr.counter;
      increment_counter();
  }
  
  sharedpointer<T>(sharedpointer<T>&& ptr)
  {
      content = ptr.content;
      counter = ptr.counter;
      ptr.content = nullptr;
      ptr.counter = nullptr;
  }
  
  
  sharedpointer<T> operator=(const sharedpointer<T>& ptr)
  {
      if(this != &ptr)
      {
          decreament_counter();
          content= ptr.content;
          counter = ptr.counter;
          increment_counter();
      }
      return *this;
  }
  
  
  sharedpointer<T> operator=(sharedpointer<T>&& ptr)
  {
      if(this != &ptr)
      {
          decreament_counter();
          content= ptr.content;
          counter = ptr.counter;
          ptr.counter = nullptr;
          ptr.counter = nullptr;
      }
      return *this;
  }
  
  void reset(T* ptr)
  {
      decreament_counter();
      content = ptr;
      counter = new int (1);
  }
  
  int get_count()
  {
      if(counter)
      {
          return (*counter);
      }
      return -1;
  }
  
  T* operator->()
  {
      return content;
  }
  
  T& operator*()
  {
      return (*content);
  }
  
  T* get()
  {
      return content;
  }
  ~sharedpointer()
  {
      decreament_counter();
  }
};

int main()
{
    sharedpointer<int> ptr1; // default constructor
    sharedpointer<int> ptr2(new int(10)); //param constructor
    sharedpointer<int> ptr3(ptr1); //cpy constructor
    ptr3 = ptr2; //copy assignment
    sharedpointer<int> ptr4(std::move(ptr1));//move cpy constructor
    ptr2 = std::move(ptr3); //move copy assignment  operator
    ptr1.reset();
    ptr1.reset(new int (5));
    cout<< (*ptr1); //implement * operator
    ptr1->func(); //implement -> opretor
    
    ptr1.get();//raw pointer
    ptr1.get_count(); // nof object pointing same resource
    
    //dtor
}
