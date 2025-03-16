
#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n;
  while(n--){
    getline(cin,s);
    while(s.find("Hoshino")!=string::npos)s.replace(s.find("Hoshino"),6,"a");
    cout<<s<<endl;
  }
  return 0;
}
//END-OF-CODE