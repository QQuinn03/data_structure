#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

template<class T>
void rotateleft (vector<T> &v)
{
    //v.clear();
   T temp;
  T item;


  cout<<"Each rotate.\n";

 for(int a = 0; a <v.size();a++)
  {
    for(int i =0; i <v.size() - 1; i++)
  {
    temp = v[i];
    v[i] = v[i+1];
    v[i+1] = temp;
  }
  for(int i = 0; i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

}

template<typename T>
void output(vector<T> v)
{
  cout<<"AFTER FINAL ROTATE:\n";
  for(int i = 0; i<v.size(); i++)
  {
    cout<<v[i]<<" ";

  }
  cout<<endl;

}

int main()
{
    vector <int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);

    vector <char> v2;
    v2.push_back('a');
    v2.push_back('b');
    v2.push_back('c');
    v2.push_back('d');

    rotateleft (v1);
    output(v1);

    rotateleft (v2);
    output(v2);

    return 0;
}
