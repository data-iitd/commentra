#include<iostream>
#include<cstring>
using namespace std;
int main(){
  int n;
  char s[10010],*c;
  cin>>n;
  while(n--){
    cin.getline(s,1010);
    while(c=strstr(s,"Hoshino"))*(c+6)='a';
    cout<<s<<endl;
  }
  return 0;
}
