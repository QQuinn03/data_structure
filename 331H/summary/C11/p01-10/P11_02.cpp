#include<iostream>
#include<iomanip>
using namespace std;

class Budget
{
private:
  static double corpBudget;
  double divBudget;

public:
  Budget() { divBudget = 0;}
  void addBudget(double b)
  {
    divBudget += b;
    corpBudget += divBudget;
  }
  double getDivBudget() const { return divBudget; }
  double getCorpBudget() const { return corpBudget; }

};

double Budget::corpBudget = 0;

int main()
{
  const int num = 4;
  Budget division[num];

  for (int i = 0; i<num; i++)
  {
    double bud;
    cout<<"Enter the budget request for dividion";
    cout<<(i+1)<<": ";
    cin>>bud;
    division[i].addBudget(bud);
  }

  cout<<showpoint<<fixed<<setprecision(2);
  cout<<"\n Here are the division budget request: \n";
  for(int i = 0; i<num; i++)
  {
    cout<<"Division "<<(i+1)<<"\t$ ";
    cout<<division[i].getDivBudget()<<endl;
  }

 cout << "Total Budget Requests:\t$";
 cout << division[0].getCorpBudget()<< endl;

 return 0;
}
