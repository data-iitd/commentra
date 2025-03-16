#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n; // Declare an integer variable to store the size of the array
  std::vector<int> data; // Declare a vector of integers

  std::cin >> n; // Read an integer value for n from the standard input
  data.resize(n); // Resize the vector to have n elements

  // Read n integers from the standard input and store them in the vector
  for (int i = 0; i < n; i++) {
    std::cin >> data[i];
  }

  int max = *std::max_element(data.begin(), data.end()); // Find the maximum value in the vector
  int index = std::distance(data.begin(), std::find(data.begin(), data.end(), max)); // Find the index of the maximum value

  int a = 0; // Initialize a variable to store the sum of elements excluding the maximum value

  // Iterate through the vector, excluding the element at the index of the maximum value, and sum up the remaining elements
  for (int i = 0; i < n; i++) {
    if (i != index) {
      a += data[i];
    }
  }

  // Compare the sum of the remaining elements (a) with the maximum value (max)
  if (a > max) {
    std::cout << "Yes" << std::endl; // Print "Yes" if the sum of remaining elements is greater than the maximum value
  } else {
    std::cout << "No" << std::endl; // Print "No" otherwise
  }

  return 0;
}
