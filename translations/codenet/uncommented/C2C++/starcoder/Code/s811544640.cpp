#include <iostream>

using namespace std;

int main(void) {
  int a, b, c;

  cin >> a >> b >> c;

  if (b > a * c) {
    cout << c << endl;
  }else {
    cout << b / a << endl;
  }

  return 0;
}

