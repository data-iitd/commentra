#include <iostream>
#include <cmath> // Include cmath for abs() function

using namespace std;

int main() {
  int N, t, x, y, nx = 0, ny = 0, nt = 0;
  int i, j, k, tmp;
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> t >> x >> y;
    tmp = t - nt - (abs(x - nx) + abs(y - ny));
    if (tmp < 0 || tmp % 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

