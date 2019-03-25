#ifndef NUMBERARRAY2_H
#define NUMBERARRAY2_H
#include<iostream>
using namespace std;

class NumberArray2
{
private:
  double *aPtr;
  int arraysize;
public:
NumberArray2 (const NumberArray2 & right)
{
  if(this != &right)
  {
    if(arraysize >0){delete[]aPtr;}
    arraysize = right.arraysize;
    aPtr = new double [arraysize];
    for(int i = 0; i<arraysize;i++)
    {
      aPtr[i] = right.aPtr[i];
    }
  }

}
NumberArray2(int size, double value)
{
  arraysize = size;
  aPtr = new double[arraysize];
  setValue(value);
}
~NumberArray2(){if(arraysize>0) delete [] aPtr;}

void print() const
{
  for(int i = 0; i<arraysize;i++)
  {
    cout<<aPtr[i]<<" ";
  }
}

void setValue(double value)
{
  for(int i = 0; i<arraysize;i++)
  {
    aPtr[i] = value;
  }
}

};
#endif
