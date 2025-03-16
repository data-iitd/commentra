#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  string ans = "No";
  if (s.find("C") < s.rfind("F")) {
    ans = "Yes";
  }
  if (s.find("C") < 0) {
    ans = "No";
  }
  
  cout << ans << endl;
  return 0;
}
