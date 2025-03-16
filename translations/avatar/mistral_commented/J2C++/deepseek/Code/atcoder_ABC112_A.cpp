#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "Hello World" << endl;
  } else {
    int num1, num2;
    cin >> num1 >> num2;
    cout << num1 + num2 << endl;
  }

  return 0;
}
