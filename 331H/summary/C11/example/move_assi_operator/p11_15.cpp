#include<iostream>
#include"overload3.h"
using namespace std;

NumberArray makeArray();

int main()
{
  NumberArray first;
  first = makeArray();
  NumberArray second = makeArray();

  cout<<endl<<"The object's date is ";
  first.print();

  cout<<endl;

  return 0;
}

NumberArray makeArray()
{
  NumberArray nArr(5, 10.5);
  return nArr;
}
