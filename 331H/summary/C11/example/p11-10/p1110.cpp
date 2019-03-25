#include<iostream>
#include"Length.h"
using namespace std;

int main()
{
  Length first(0), second(0), third(0);
  int f,i;
  cout<<"enter a distance in feet and inches: ";
  cin>>f>>i;
  first.setLength(f,i);
  cout<<"enter another distance in feet and inches: ";
  cin>>f>>i;
  second.setLength(f,i);

  third = first + second;
  cout<<"first + second = ";
  cout<<third.getFeet()<<" feet ."<<third.getInches()<<" inches."<<endl;
  third = first - second;
  cout<<"first - second = ";
  cout<<third.getFeet()<<" feet ."<<third.getInches()<<" inches."<<endl;

  cout<<"compare first and second: "<<(first == second)<<endl;

  return 0;


}
