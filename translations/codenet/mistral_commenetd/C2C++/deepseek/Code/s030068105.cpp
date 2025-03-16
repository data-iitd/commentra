#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

int main() {
  int n; // Declare an integer variable 'n' to store the number of elements in the array

  std::cout << "Enter the number of elements: ";
  std::cin >> n;

  std::vector<int> data(n); // Declare a vector 'data' to store the elements

  // Read each element of the array from the user
  for(int i = 0; i < n; i++) {
    std::cout << "Enter element " << i + 1 << ": ";
    std::cin >> data[i];
  }

  int max = *std::max_element(data.begin(), data.end()); // Find the maximum element
  int a = 0; // Initialize 'a' variable to store the sum of all elements except the maximum

  // Calculate the sum of all elements except the maximum
  for(int i = 0; i < n; i++) {
    if(data[i] != max) a += data[i];
  }

  // Check if the sum of all elements except the maximum is greater than the maximum
  if(a > max) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
