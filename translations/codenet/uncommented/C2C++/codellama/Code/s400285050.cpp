#include<iostream>

using namespace std;

int you(int,int);
int main(){
  int x,y,z;
  cin>>x>>y;
  if(x>=y)z=you(x,y);
  else z=you(y,x);
  cout<<z<<endl;
  return 0;
}
int you(int x ,int y){
  int z;
  while(1){
    z=x%y;
    x=y;
    y=z;
    if(y<=0)break;
  }
  return x;

}