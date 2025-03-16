#include <iostream>
#include <vector>
using namespace std;

#define N 1000000
#define Q 50000

int n, S[N], T[Q];

int binarySearch(int key)
{
  int left = 0, right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (S[mid] == key) return 1;
    else if (key < S[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}

int main()
{
  int i, j, q, c = 0;

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> S[i];
  }

  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> T[i];
    if (binarySearch(T[i]) == 1) c++;
  }

  cout << c << endl;

  return 0;
}
