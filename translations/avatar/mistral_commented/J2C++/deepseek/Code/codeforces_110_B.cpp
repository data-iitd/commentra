#include <iostream>
using namespace std;

int main() {
  int n;
  int i, j;
  char* c;
  char p = 'a';

  cin >> n;
  c = new char[n];

  for (i = 0; i < 4; i++) {
    for (j = i; j < n; j += 4) {
      c[j] = p;
      p++;
    }
  }

  for (i = 0; i < n; i++) {
    cout << c[i];
  }

  delete[] c;
  return 0;
}

