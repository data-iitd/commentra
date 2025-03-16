#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Input struct to handle reading from standard input
struct Input {
  int n;
  vector<int> a;
  Input() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> n;
    for (int i = 0; i < n; i++) {
      int x;
      ss >> x;
      a.push_back(x);
    }
  }
};

int main() {
  Input input;
  int n = input.n;
  vector<int> a = input.a;
  int m = 0;
  for (int c = 1; c < n-1; c++) {
    int f = 0;
    for (int k = 0; c < n-1-k*c; k++) {
      bool u = false;
      if (k*c < n-1) { u = true; }
      if (n-1-k*c < n-1) { u = true; }
      if (u) { break; }
      f += a[n-1-k*c] + a[k*c];
      if (m < f) { m = f; }
    }
  }
  cout << m << endl;
}

