#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, ans = 0;
  string a, b, c;
  cin >> n;
  cin >> a >> b >> c;
  
  for(int i = 0; i < n; i++){
    if(a[i] == b[i] and b[i] == c[i]):
      pass
    elif(a[i] == b[i] or b[i] == c[i] or a[i] == c[i]):
      ans += 1
    else:
      ans += 2
  }
  print(ans)
}
