#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n--){
    string s;
    getline(cin,s);
    while(s.find("Hoshino")!=-1)s.replace(s.find("Hoshino"),7,"a");
    cout<<s;
  }
  return 0;
}
