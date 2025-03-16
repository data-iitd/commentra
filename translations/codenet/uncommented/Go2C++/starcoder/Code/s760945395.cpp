#include <iostream>

using namespace std;

int main() {
  for (int i=0;i<5;i++) {
    int a;
    cin >> a;
    if (a == 0) {
      cout << i+1 << endl;
    }
  }
}
