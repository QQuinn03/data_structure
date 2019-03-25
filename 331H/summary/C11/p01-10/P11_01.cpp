#include<iostream>
using namespace std;
class Example
{
  int x;
public:
  Example(int a) {x = a;}
  void setValue(int a)
    { x = a;}
  void AddressandValue()
  {
    cout<<"The object at adrress "<<this<<" has "
       <<"value "<<(*this).x<<endl;
  }
};

int main()
{
  Example ob1(10), ob2(20);

  cout<<"Addresses of objects are "<<&ob1<<" and "<<&ob2<<endl;

  ob1.AddressandValue();
  ob2.AddressandValue();

  return 0;
}
