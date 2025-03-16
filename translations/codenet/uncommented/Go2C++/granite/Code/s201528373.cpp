
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  
  int tmpSum = 0;
  int rs = 0;
  for (int i = 0; i < n; i++) {
    tmpSum += l[i];
    if (tmpSum <= x) {
      rs = i + 2;
    } else {
      break;
    }
  }
	cout << rs << endl;
}

