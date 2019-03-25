#ifndef NUMDAYS_H
#define NUMDAYS_H
#include <iostream>
using namespace std;

class NumDays
{
	int Hrs;  // Number of work hours

public:
	NumDays()
	{ Hrs = 0; }
	NumDays(int Hrs)
	{ this->Hrs = Hrs; }
	void setHours(int Hrs)
	{ this->Hrs = Hrs; }
	int getHours()
	{ return Hrs;}
	void setDays(double d)
  {
    Hrs = (d*8);
  }
	double getDays()
  { return (Hrs/8.0);}

	/* line 25-35  how to overoload an opearator P739
	 Make the overloaded member function a separate,
	  stand-alone function . */
	friend NumDays operator+(NumDays a, NumDays b)
  {
    return NumDays(a.Hrs + b.Hrs);
  }
	friend NumDays operator-(NumDays X, NumDays Y)
  {
    return NumDays(X.Hrs - Y.Hrs);
  }
	NumDays operator++()
  {
    Hrs += 1.0;
    return *this;
  }
	NumDays operator++(int)
  {
    Hrs += 1.0;
    return *this;
  }
	NumDays operator--()
  {
    if(Hrs>1.0)
      Hrs -= 1.0;
    return *this;
  }
	NumDays operator--(int)
  {
    if (Hrs > 1.0)
		Hrs -= 1.0;

	return *this;
  }
};
#endif
