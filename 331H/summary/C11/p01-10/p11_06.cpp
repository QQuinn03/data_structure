#include<iostream>
#include<string>

using namespace std;

class Address
{
private:
  string street;

public:
  Address() {street = '';}
  Address(string st) {setStreet(st);}
  void setStreet(string st) {street = st;}
  string getStreet() const {return street;}
};

int main()
{
  Address mary("123 main street");
  Address joan = mary;

  cout<<"Mary lives at "<<mary.getStreet()<<endl;
  cout<<"Joan lives at "<<joan.getStreet()<<endl;

  joan.setStreet("1245 main street");

  cout<<"Mary lives at "<<mary.getStreet()<<endl;
  cout<<"Joan lives at "<<joan.getStreet()<<endl;

  return 0;

}
