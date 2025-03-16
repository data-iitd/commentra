// Package main is the entry point of the program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

// Define the main function
int main() {
  // Initialize the input reader
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // Read the first integer from the input
  int n;
  std::cin >> n;

  // Read the second integer array from the input
  std::vector<int> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }

  // Initialize a boolean slice of size n
  std::vector<bool> u(n);

  // Initialize two integer variables m and f
  long long m = 0, f = 0;

  // Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
  for (int c = 1; c < n-1; c++) {
    // Initialize a variable f to 0
    f = 0;

    // Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
    for (int k = 0; k < n-1-c*c; k++) {
      // Set the boolean value of the current index to true
      u[k*c] = true;

      // Check if the boolean value of the last index of the current subarray is already set to true
      // If it is, break the inner loop as we don't need to check further
      if (u[n-1-k*c]) { break; }

      // Calculate the sum of the current and previous subarrays
      f += s[n-1-k*c] + s[k*c];

      // Update the value of m if the current sum is greater than the previous maximum sum
      if (m < f) { m = f; }

      // Set all the boolean values of the current subarray to false
    }

    // Iterate through all the indices of the current subarray and set their boolean values to false
    for (int k = 0; k*c < n-1; k++) { u[k*c] = false; }
  }

  // Print the maximum sum
  std::cout << m << std::endl;

  return 0;
}

// 