#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, q, k, sum = 0;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> k;
    if (binary_search(A.begin(), A.end(), k)) {
      sum++;
    }
  }
  cout << sum << endl;
  return 0;
}

