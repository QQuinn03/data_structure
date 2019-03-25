/*A positive integer greater than 1 is said to be prime if
it has no divisors other than 1 and itself. A positive integer
greater than 1 is a composite if it is not prime. Write a program
that asks the user to enter an integer greater than 1 and prints
the list of all prime numbers less than or equal to the number entered.
Your program should use a predicate (function object or a lambda)
that determines whether a given integer is composite .
 The program should generate the list of prime numbers
 less or equal to X by adding all positive integers greater
  than 1 to a vector and then using the remove_if function
  and the predicate to remove all composites from the vector.*/

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class isComposite
{
public:
  bool operator()(int x)
  {
    for(int i = 2; i<x;i++)
    {
      if(x%i == 0)
      return true;
    }
    return false;
  }
};


int main()
{
  int number;
  cout<<"ENTER a number and find out all prime numbers"
      <<"less than or equal to it: \n";
  cin>>number;

  vector<int> num(number-1);
  for(int i=0; i<number-1; i++)
   {
     num[i]=2+i;
   }

   cout<<"Here are the numbers under "<<number<<endl;
   for(int e:num){cout<<e<<" ";}
   cout<<endl;

   auto start_removed = remove_if(begin(num), end(num),isComposite());
   num.erase(start_removed, end(num));

   cout<<"Here are the prime numbers under "<<number<<endl;
   for(int e:num){cout<<e<<"  ";}
   cout<<endl;

   return 0;
}
