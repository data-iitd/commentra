#include<iostream>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  c*=2;
  if(a+b<=c)
    cout<<a*x+b*y<<endl;
  else{
    if(x<=y){
      if(b<=c)
        cout<<c*x+(y-x)*b<<endl;
      else
        cout<<c*y<<endl;
    }
    else{
      if(a<=c)
        cout<<c*y+(x-y)*a<<endl;
      else
        cout<<c*x<<endl;
    }
  }
  return 0;
}
