#include<iostream>

using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;

public:
  // Copy assignment and copy constructor
  NumberArray& operator = (const NumberArray &right)
  {
    cout<<"Copy assignment operator running\n";
    if(this != &right)
    {
      if(arraySize >0)
      {
        delete[] aPtr;
      }
      arraySize = right.arraySize;
      aPtr = new double[arraySize];
      for(int index = 0; index<arraySize;index++)
      {
        aPtr[index]= right.aPtr[index];
      }
    }
    return *this;
  }

  NumberArray(const NumberArray &obj)
{
  cout<<"Copy constructor running\n";
  arraySize = obj.arraySize;
  aPtr = new double[arraySize];
  for(int index = 0; index<arraySize;index++)
  {
    aPtr[index]= obj.aPtr[index];
  }
}

//Move assignment and move constructor
NumberArray& operator= (NumberArray &&r)
{
  cout << "Move assignment is running\n"; // Trace
   if (this != &r)
  {
    swap(arraySize, r.arraySize);
    swap(aPtr, r.aPtr );
  }
   return *this;
}

NumberArray(NumberArray && temp)
{
// "Steal" the resource from the temp object
  this->arraySize = temp.arraySize;
  this->aPtr = temp.aPtr;
// Put the temp object in a safe state // for its destructor to run
  temp.arraySize = 0;
  temp.aPtr = nullptr;
}

NumberArray()
{
  cout << "Default constructor running\n";
  arraySize = 2;
  aPtr = new double[arraySize];
  setValue(0.0);
}

NumberArray(int size1, double value)
{
cout << "Regular constructor running\n";
arraySize = size1;
aPtr = new double[arraySize];
setValue(value);
}

void setValue(double value)
{
for (int index = 0; index < arraySize; index++)
  {
    aPtr[index] = value;
  }
}

void print() const
{
for (int index= 0; index< arraySize; index++)
  {
    cout << aPtr[index] <<"  ";
  }
}

~NumberArray()
{
  cout<<"Destructor running \n";
  if(arraySize > 0)
  {
    delete[] aPtr;
  }
}

};
