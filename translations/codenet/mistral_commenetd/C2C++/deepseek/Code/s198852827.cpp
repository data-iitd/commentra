#include <iostream>
#include <cmath> // For std::abs

int main() {
  int N; // Variable to store the number of test cases
  int t, x, y, nx = 0, ny = 0, nt = 0; // Variables to store the current test case data and previous coordinates
  int i, j, k, tmp; // Loop variables

  // Read the number of test cases
  std::cin >> N;

  // Loop through each test case
  for (i = 0; i < N; i++) {
    // Read the current test case data (t, x, y)
    std::cin >> t >> x >> y;

    // Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
    tmp = t - nt - (std::abs(x - nx) + std::abs(y - ny));

    // Check if the current test case satisfies the condition
    if (tmp < 0 || tmp % 2) {
      // If the condition is not satisfied, print 'No' and exit the program
      std::cout << "No" << std::endl;
      return 0;
    }

    // Update the previous coordinates for the next iteration
    nx = x;
    ny = y;
    nt = t;
  }

  // If all the test cases satisfy the condition, print 'Yes'
  std::cout << "Yes" << std::endl;
  return 0;
}
