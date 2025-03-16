#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int64_t> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int64_t m = 0;
  for (int c = 1; c < n - 1; c++) {
    vector<bool> u(n, false);
    int64_t f = 0;
    for (int k = 0; k * c < n - 1; k++) {
      if (u[k * c]) break;
      u[k * c] = true;
      if (k * c + c < n - 1) u[k * c + c] = true;
      f += s[k * c] + s[k * c + c];
      if (m < f) m = f;
    }
  }
  cout << m << endl;
  return 0;
}

