#include"DyStack.h"
#include<iostream>
#include<stack>
using namespace std;

int main()
{
  Dystack<int> p1;
  p1.push(3);
  p1.push(4);
  p1.push(5);
  p1.push(6);

  p1.pop();
  p1.pop();
  p1.pop();
  //p1.pop();
  cout<<p1.isEmpty();
  cout<<endl;

  return 0;
}
