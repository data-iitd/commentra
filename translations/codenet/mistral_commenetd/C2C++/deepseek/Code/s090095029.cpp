#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  // Declare variables
  int n, m;

  // Read input values for n and m
  std::cin >> n >> m;

  // Initialize boolean vector r0 with all elements set to false
  std::vector<bool> r0(n, false);

  // Initialize integer vector r1 and counter for its size
  std::vector<int> r1;

  // Process each of the m input pairs
  for (int i = 0; i < m; i++) {
    // Read input values for a and b
    int a, b;
    std::cin >> a >> b;

    // Swap a and b if a is greater than b
    if (a > b) {
      std::swap(a, b);
    }

    // If a is equal to 1, set the corresponding element in r0 to true
    if (a == 1) r0[b - 1] = true;

    // If b is equal to n, add its index to r1
    if (b == n) r1.push_back(a - 1);
  }

  // Initialize boolean variable res to false
  bool res = false;

  // Check if there exists any pair in r1 whose corresponding element in r0 is true
  for (int i = 0; i < r1.size(); i++) {
    // If such a pair is found, set res to true
    if (r0[r1[i]]) res = true;
  }

  // Output the result based on the value of res
  std::cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;

  // Return 0 to indicate successful execution
  return 0;
}

