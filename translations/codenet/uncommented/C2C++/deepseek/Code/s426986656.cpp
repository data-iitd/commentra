#include <iostream>
using namespace std;

int main() {
  int A, B, flag = 0;
  cin >> A >> B;

  for(int i=1; i<=3; ++i) {
    if((A*B*i)%2 == 1) {
      flag = 1;
      break;
    }
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

