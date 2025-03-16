#include <iostream>  // Include standard input-output stream library
#include <vector>  // Include library for dynamic arrays
#include <algorithm>  // Include library for sorting and other algorithms

int main() {
  int n, m;
  std::cin >> n >> m;  // Read two integers n and m from standard input
  std::vector<bool> r0(n, false);  // Initialize vector r0 with false values
  std::vector<int> r1;  // Initialize vector r1
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;  // Read pairs of integers a and b
    if (a > b) {
      std::swap(a, b);  // Ensure a is less than or equal to b
    }
    if (a == 1) r0[b - 1] = true;  // If a is 1, set r0[b-1] to true
    if (b == n) r1.push_back(a - 1);  // If b is n, add a-1 to r1
  }
  bool res = false;
  for (int i = 0; i < r1.size(); i++) {
    if (r0[r1[i]]) res = true;  // Check if any element in r1 has a true in r0
  }
  std::cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;  // Print "POSSIBLE" if res is true, otherwise print "IMPOSSIBLE"
  return 0;
}
