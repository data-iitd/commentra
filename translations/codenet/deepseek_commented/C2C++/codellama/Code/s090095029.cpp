#include <iostream>  // Include standard input-output library
#include <cstring>  // Include library for string manipulation

using namespace std;  // Use standard namespace

int main() {
  int n, m;
  cin >> n >> m;  // Read two integers n and m from standard input
  bool r0[n];
  memset(r0, 0x00, n);  // Initialize array r0 with false values
  int r1[n];
  int nr1 = 0;  // Initialize array r1 and set nr1 to 0
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;  // Read pairs of integers a and b
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }  // Ensure a is less than or equal to b
    if (a == 1) r0[b - 1] = true;  // If a is 1, set r0[b-1] to true
    if (b == n) r1[nr1++] = a - 1;  // If b is n, add a-1 to r1
  }
  bool res = false;
  for (int i = 0; i < nr1; i++) {
    if (r0[r1[i]]) res = true;  // Check if any element in r1 has a true in r0
  }
  cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << endl;  // Print "POSSIBLE" if res is true, otherwise print "IMPOSSIBLE"
  return 0;
}

