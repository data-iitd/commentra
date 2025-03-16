

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

class Input {
public:
  Input() : reader(new BufferedReader(new InputStreamReader(System.in))) {}
  string NextLine() {
    string line;
    while (true) {
      line = reader->readLine();
      if (line.length() > 0) break;
    }
    return line;
  }
  int NextInt() {
    int n;
    istringstream is(NextLine());
    is >> n;
    return n;
  }
  vector<int> NextIntArray() {
    string line = NextLine();
    stringstream ss(line);
    vector<int> a;
    int n;
    while (ss >> n) a.push_back(n);
    return a;
  }
private:
  BufferedReader *reader;
};

int main() {
  Input input;
  int n = input.NextInt();
  vector<int> s = input.NextIntArray();
  vector<bool> u(n, false);
  ll m = 0, f = 0;
  for (int c = 1; c < n - 1; c++) {
    f = 0;
    for (int k = 0; c < n - 1 - k * c; k++) {
      u[k * c] = true;
      if (u[n - 1 - k * c]) break;
      f += s[n - 1 - k * c] + s[k * c];
      if (m < f) m = f;
    }
    for (int k = 0; k * c < n - 1; k++) u[k * c] = false;
  }
  cout << m << endl;
  return 0;
}

