#ifndef LENGTH_H
#define LENGTH_H
#include<iostream>
using namespace std;

class Length
{
private:
  int len_inches;
public:
  Length(int feet, int inches)
  {
    setLength(feet, inches);
  }
  Length(int inches) {len_inches = inches;}
  int getFeet() const {return len_inches /12;}
  int getInches() const {return len_inches%12;}
  void setLength(int feet, int inches)
  {
    len_inches = feet * 12 + inches;
  }

  friend Length operator+ (Length a, Length b)
  {
    return Length(a.len_inches) + Length(b.len_inches);
  }

  friend Length operator-(Length a, Length b)
  {
    return Length(a.len_inches) - Length(b.len_inches)
  }

  friend bool operator<(Length a, Length b)
  {
    return a.len_inches < b.len_inches;
  }
  friend bool operator==(Length a, Length b)
  {
    return a.len_inches == b.len_inches;
  }

  Length operator++();
  {
    return this->len_inches++;
  }

  Length operator(int)
  {
    Length temp = *this;
    len_inches ++;
    return temp;
  }

  friend ostream &opeartor<<(ostream &out, Length a)
  {
    out<<"The length is: "<<a.getFeet()<<" feet"
       << a.getInches<<" inches."<<endl;
    return out;   
  }
  friend istream &opeartor>>(istream &in, Length &a)
  { int feet, inches;
    cout<<"Enter feet: ";
    in>>feet;
    cout<<"Enter inches ";
    in>>inches;

    a.setLength(feet, inches);
    return in;
  }


};
#endif
