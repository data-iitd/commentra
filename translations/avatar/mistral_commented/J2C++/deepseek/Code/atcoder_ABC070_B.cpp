#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (c > b) {
    cout << 0 << endl;
    return 0;
  }

  if (a > d) {
    cout << 0 << endl;
    return 0;
  }

  if (a < c) {
    int difference = min(b, d) - c;
    cout << difference << endl;
    return 0;
  }

  vector<int> l = {a, b, c, d};
  sort(l.begin(), l.end());

  int difference = l[2] - l[1];
  cout << difference << endl;

  return 0;
}

