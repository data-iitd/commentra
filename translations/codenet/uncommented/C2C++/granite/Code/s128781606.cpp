
#include <iostream>
using namespace std;
int main(void) {
  int A,B,C,D,E,max;
  cin >> A >> B;
  C = A+B;
  D = A-B;
  E = A*B;
  max = C;
  if (max<D) {
    max = D;
  }
  if (max<E) {
    max = E;
  }
  cout << max << endl;
  return 0;
}
