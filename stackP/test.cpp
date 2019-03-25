#include<iostream>
#include<string>
#include<cctype>
#include"StaExpre.h"
using namespace std;


int order(char);
int evaluate(string);
int calculation(int, int, char);

int main()
{

  cout<< evaluate("(-1*9-(-3+2*5-(-2)))-(-3-1*4)")<<endl; //answer is -11
  cout<< evaluate("-1*(-1*(-1)*(-2*(-3*(-2)-1)-1)-(-1-1*1))")<<endl;//answer is 9
  cout<<evaluate("4/(-2)")<<endl;
  cout<<evaluate("-4/(-2)")<<endl;
  cout<<evaluate(" -4/(-2)")<<endl;

return 0;
}

int order(char op)
{
  if(op == '+' || op =='-')
    return 1;
  if(op == '*' || op =='/')
    return 2;
  return 0;
}

int calculation(int a,int b,char op)
{
  if(op == '-') return b - a;  //last out - first out eg. "3-2", 3 will be first in. then 2 in
  if(op == '+') return b + a;
  if(op == '*') return b * a;
  if(op == '/') return b / a;
  return 0;
}

int evaluate(string expression)
{
  int len = expression.length();

  StaExpre<int> operand;
  StaExpre<char> oper;

  for(int i =0;i<len;i++)
  {
    if(expression[i] ==' ')
      {  continue; }

    //check if there is more than one digit, such as '23+1','345+1'
    else if (isdigit(expression[i]))
    {
      int val = 0;
      //when chars doing math, they turn to int and return back a strange number.
      //so we need to do integer promotion
      while(i<len && isdigit(expression[i]))
      {
        val = val * 10 +(expression[i]-'0');
        i++;
      }
       operand.push(val);
       i--; // eg. a = "23+1" after the above while loop i = 2, so we need to
    }       //deduce 1 here to make sure '+' will be the next char evaluated

    else if(expression[i] =='(')
      { oper.push(expression[i]); }

    else if(expression[i] ==')')
     {
       while(!oper.isEmpty() &&oper.getTop()!='(') // there might be(3*(2+3)), so oper.getTop()!='('
       {
          int a = operand.getTop();
          operand.pop();
          int b = operand.getTop();
          operand.pop();
          char c = oper.getTop();
          oper.pop();
          operand.push(calculation(a,b,c));
       }
       oper.pop();
     }

     //eg. 3*2+1 . at this step all parentheses are dealt with
     else
     {
       if(expression[i] == '-')   //negative number shows like (-1)
       {
         if(oper.getTop() == '(')
         {
           operand.push(0);
         }
       }

       while(!oper.isEmpty() && order(oper.getTop()) >= order(expression[i]))
       {
         int a = operand.getTop();
         operand.pop();
         // int b = operand.getTop();
         // operand.pop();
         int b;
         if(operand.isEmpty()) //the first number is a negative number.eg"-1 +2"
           {  b = 0;}
         else
           {
             b = operand.getTop();
             operand.pop();
           }
         char c = oper.getTop();
         oper.pop();
         operand.push(calculation(a,b,c));
       }
       oper.push(expression[i]);
     }

  }
  //last step, calculate what's remainning in the two stacks
  //at this step the there is nothing left in the expression
  while(!oper.isEmpty())
  {
    int a = operand.getTop();
    operand.pop();
    // int b = operand.getTop();
    // operand.pop();
    int b;
    if(operand.isEmpty())
      {  b = 0;}
    else
      {
        b = operand.getTop();
        operand.pop();
      }
    char c = oper.getTop();
    oper.pop();
    operand.push(calculation(a,b,c));
  }
  return operand.getTop();
}
