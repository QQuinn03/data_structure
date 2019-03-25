#include"NumberArray2.h"
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
  NumberArray2 first(3, 10.6);

  NumberArray2 second=first;

  //second = first;

  cout<<"first value and its address: \n";
  first.print();
  cout<<hex<<&first<<endl;
  cout<<"\nsecond value and its address: \n";
  second.print();
  cout<<" "<<hex<<&second<<endl;

  cout<<"\nnow changed second value\n";
  second.setValue(20.4);
  cout<<"\nsecond value: \n";
  second.print();
  cout<<"\nfirst value: \n";
  first.print();
  cout<<endl;


}
