
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
  int n, m;
  int i;
  int a[100006];
  int b[100006];
  int cnt = 0;
  int t;

  // Read the number of elements and the number of pairs
  cin >> n >> m;

  // Read the pairs of integers into arrays 'a' and 'b'
  for (i = 0; i < m; i++) cin >> a[i] >> b[i];

  // Sort the pairs using the quicksort function
  vector<pair<int, int>> v;
  for (i = 0; i < m; i++) v.push_back({a[i], b[i]});
  sort(v.begin(), v.end());

  // Count the number of unique intervals
  t = 0;
  for (i = 0; i < m; i++) {
    if (t <= v[i].first) {
      t = v[i].second;
      cnt++;
    }
  }

  // Print the count of unique intervals
  cout << cnt << endl;

  return 0;
}

