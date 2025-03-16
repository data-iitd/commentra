#include <iostream>
using namespace std;
int main (){
  long long int a,b,c;
  cin>>a>>b>>c;

  long long int d=c-a-b;
  if( ( d>0 ) && ( (4*a*b) < d*d ) )
    cout<<"Yes\n";
  else
    cout<<"No\n";

  return 0;
}

