#ifndef OVERLOAD_H
#define OVERLOAD_H

#include<iostream>
using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;

public:
  //overload operator functions
  NumberArray& operator = (const NumberArray &right)
  {
     if(this != &right)
     {
       if (this->arraySize >0){delete [] aPtr;}

       arraySize = right.arraySize;
       aPtr = new double[arraySize];
       for(int i = 0; i<arraySize;i++)
       {
         aPtr[i] = right.aPtr[i];
       }
     }
     return *this;
  }

  //copy constructor
  NumberArray(const NumberArray &obj)
  {
     this->arraySize = obj.arraySize;
     for(int i = 0; i<arraySize;i++)
     {
       aPtr[i] = obj.aPtr[i];
     }

  }

  NumberArray(int size, double v)
  {
     arraySize = size;
     aPtr = new double[arraySize];
     setValue(v);
  }

  ~NumberArray()
  {

    delete [] aPtr;
   }
  void setValue(double v)
  {
    for(int i =0; i<arraySize;i++)
    {
      aPtr[i] = v;
    }
  }

  void print () const
  {
    for(int i =0; i<arraySize;i++)
    {
      cout<<aPtr[i]<<" ";
    }
  }

};
#endif
