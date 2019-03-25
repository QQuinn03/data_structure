#include<iostream>
#include<iomanip>
using namespace std;

class Aux
{
private:
  double auxBudget;
public:
  Aux() { auxBudget = 0; }
  void addBudget(double b)
  {
    auxBudget += b;
    Budget::corpBudget += auxBudget;
  }
  double getDivBudget()const { return auxBudget; }
};

class Budget
{
private:
  static double corpBudget;
  double divBudget;
public:
  Budget(){divBudget = 0;}
  void addBudget(double b)
  {divBudget += b;
    corpBudget += divBudget;
  }
  double getDivBudget() const {return divBudget;}
  static double getCorpBudget() {return corpBudget;}
  static void mainOffice(double r)
  {
    corpBudget += r;
  }
  friend class Aux;

};

double Budget::corpBudget = 0;

int main()
{
  const int NUM = 4;
  Budget division[NUM];
  Aux auxOffice[NUM];
  double amount;

  cout<<"What's the amount for main office budget: \n";
  cin>>amount;
  Budget::mainOffice(amount);

  cout<<"\n Enter the budget requests for the divisions and  "
      <<"\n their auxiliary offices as prompted: \n";

  for (int i = 0; i<NUM; i++)
  {
    double bud;
    cout<<"Division "<<(i+1)<<": ";
    cin>>bud;
    division[i].addBudget(bud);
    cout<<"Division "<<(i+1)<<"'s auxiliary office: ";
    cin>>bud;
    auxOffice[i].addBudget(bud);
  }

  cout<<showpoint<<fixed<<setprecision(2);
  cout<<"\n Here are the division budget request: \n";
  for(int i = 0; i<NUM; i++)
  {
    cout<<"\tDivision "<<(i+1)<<"\t\t\t$ ";
    cout<<setw(7);
    cout<<"\tAuxiliary office of Division "<<(i+1);
    cout<<"\t$  ";
    cout<<auxOffice[i].getDivBudget()<<endl;
  }
  cout<<"\t Total requests (including main office): $";
  cout<<Budget::getCorpBudget()<<endl;

  return 0;

}
