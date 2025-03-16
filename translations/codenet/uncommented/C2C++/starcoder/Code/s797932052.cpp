#include<iostream>
using namespace std;

int main(void)
{
  int a,b;
  cin>>a;
  cin>>b;
  if((a*b)%2 == 0){
    cout<<"Even\n";
}else{
    cout<<"Odd\n";
  }
  return 0;
}
