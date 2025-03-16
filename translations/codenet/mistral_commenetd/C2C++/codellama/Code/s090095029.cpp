
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  // Declare variables
  int n, m;

  // Read input values for n and m
  cin >> n >> m;

  // Initialize boolean array r0 with all elements set to false
  bool r0[n];
  memset(r0, 0x00, n * sizeof(bool));

  // Initialize integer array r1 and counter for its size
  int r1[n];
  int nr1 = 0;

  // Process each of the m input pairs
  for (int i = 0; i < m; i++) {
    // Read input values for a and b
    int a, b;
    cin >> a >> b;

    // Swap a and b if a is greater than b
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }

    // If a is equal to 1, set the corresponding element in r0 to true
    if (a == 1) r0[b - 1] = true;

    // If b is equal to n, add its index to r1
    if (b == n) r1[nr1++] = a - 1;
  }

  // Initialize boolean variable res to false
  bool res = false;

  // Check if there exists any pair in r1 whose corresponding element in r0 is true
  for (int i = 0; i < nr1; i++) {
    // If such a pair is found, set res to true
    if (r0[r1[i]]) res = true;
  }

  // Output the result based on the value of res
  cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << endl;

  // Return 0 to indicate successful execution
  return 0;
}

