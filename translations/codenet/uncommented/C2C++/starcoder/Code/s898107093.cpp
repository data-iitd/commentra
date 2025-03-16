#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int n,taro=0,hanako=0,i;
  cin>>n;
  char **t,**h;
  t=new char*[n];
  h=new char*[n];
  for(i=0;i<n;i++){
    t[i]=new char[100];
    h[i]=new char[100];
    cin>>t[i];
    cin>>h[i];
    if(strcmp(t[i],h[i])<0) hanako+=3;
    if(strcmp(t[i],h[i])>0) taro+=3;
    if(strcmp(t[i],h[i])==0){
      taro+=1;
      hanako+=1;
    }
    delete[] t[i];
    delete[] h[i];
  }
  cout<<taro<<" "<<hanako<<endl;
  return 0;
}
