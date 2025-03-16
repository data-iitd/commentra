#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> l;
  for (int i = 0; i < n; i++) {
    int tmpL;
    cin >> tmpL;
    l.push_back(tmpL);
  }
  
  int tmpSum = 0;
  int rs = 0;
  for (int i = 0; i < n; i++) {
    tmpSum += l[i];
    if (tmpSum <= x) {
      rs = i + 2;
    } else if (tmpSum > x) {
      break;
    }
  }
  cout << rs << endl;
}
