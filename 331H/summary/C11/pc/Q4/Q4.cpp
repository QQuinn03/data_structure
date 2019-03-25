// This program tests the NumDays class by inputting and retrieving values for
// hours and days.
#include <iostream>
#include "NumDays.h"
using namespace std;

int main()
{
	NumDays a, b, c;

	a.setHours(18);
	cout << "Employee A hours worked: " << a.getHours() << endl;

	b.setDays(3.5);
	cout << "Employee B hours worked: " << b.getHours() << endl;

	c = b-a;

	cout << "Employee B - Employee A = " << c.getHours() << " hours." << endl;

	c = a+ b;

	cout << "Employee A + Employee B = " << c.getHours() << " hours." << endl;

	cout << "Employee A days worked: " << a.getDays() << endl;

	cout << "Employee B days worked: " << b.getDays() << endl;

	++a;

	cout << "Increment Employee A using prefix operator: "
		 << a.getHours() << endl;

	b++;

	cout << "Increment Employee B using postfix operator: "
		 << b.getHours() << endl;

	--b;

	cout << "Decrement Employee A using prefix operator: "
		 << a.getHours() << endl;

b--;

	cout << "Decrement Employee B using postfix operator: "
		 << b.getHours() << endl;


	return 0;
}
