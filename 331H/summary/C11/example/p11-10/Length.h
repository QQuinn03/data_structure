#ifndef LENGTH_H
#define LENGTH_H
#include <iostream>
using namespace std;

class Length
{
private:
  int len_inches;
public:
  Length (int feet, int inches)
  {
    setLength(feet, inches);
  }

  Length(int inches) { len_inches = inches;}
  int getFeet() const {return len_inches/12;}
  int getInches() const { return len_inches % 12;}
  void setLength (int feet, int inches)
  {
    len_inches = 12 * feet + inches;
  }

 Length operator+(Length b)
  {
     return Length(this->len_inches + b.len_inches);

  }
 Length operator-(Length b)
  {
    if(this->len_inches>b.len_inches) {return Length(this->len_inches - b.len_inches);  }
    return  Length(b.len_inches - this->len_inches);
  }

  bool operator<(Length b)
  {
    return this->len_inches < b.len_inches;
  }

  bool operator == (Length b)
  {
    return this->len_inches == b.len_inches;
  }

};
#endif
