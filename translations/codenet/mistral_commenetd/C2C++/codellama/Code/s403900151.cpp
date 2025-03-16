#include <iostream>
using namespace std;

int main() {
  int n, r, p, c;
  int i, j, k, l;
  int a[51], b[51];

  while (1) {
    cin >> n >> r;
    if (!n && !r)
      break;

    for (i = 0; i < n; i++)
      a[i] = i + 1;

    for (i = 0; i < r; i++) {
      cin >> p >> c;

      for (j = 0; j < c; j++)
        b[j] = a[n - p - c + 1 + j];

      for (j = 0; j < p - 1; j++)
        a[n - p + j + 1] = a[n - p + j];

      for (j = n - p - c + 1, k = 0; k < c; j++, k++) {
        a[j] = b[k];
      }

      cout << a[n - 1] << endl;
    }
  }
  return 0;
}

