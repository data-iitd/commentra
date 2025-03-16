
#include <iostream>

using namespace std;

int main() {
  long long  n,a,m,M,c,b,i;
  c = 0;
  m = 100000000;
  M =-100000000;
  cin >> n;

  for(i=1; i<=n; i++){
    cin >> a;
    if(a>M) {
      M = a;
    } 
    if(a < m){
      m = a;
    }
    c = c+a;
  }
    cout << m << " " << M << " " << c << endl;

  return 0;
}
