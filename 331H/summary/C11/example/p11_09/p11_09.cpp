#include<iostream>
#include<iomanip>
#include "overload.h"
using namespace std;

int main()
{
  NumberArray first(3, 10.5);
  NumberArray second(5, 20.5);

  // Display the values of the two objects
  cout<<setprecision(2)<<fixed<<showpoint;
  cout<<"First object's data is ";
  first.print();
  cout << endl << "The second object's data is";
  second.print();

  // Call the overloaded operator
  cout << "\n Now we will assign the second object "
       << "to the first."<< endl;
  first = second;
  second.setValue(11.9);

// Display the new values of the two objects
cout << "First object's data is";
first.print();
cout<<&first<<endl;
cout << endl << "The second object's data is";
    second.print ();
    cout<<endl;

  return 0;
}
