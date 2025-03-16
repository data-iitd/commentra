#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int n; // Declare an integer variable to store the size of the array
  int *data; // Declare a pointer to an array of integers

  cin >> n; // Read an integer value for n from the standard input
  data = (int*)malloc(sizeof(int) * n); // Allocate memory for an array of integers with size n

  // Read n integers from the standard input and store them in the allocated array
  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }

  int max = 0, index = 0; // Initialize max to 0 and index to 0 (assuming the first element is the maximum initially)

  // Iterate through the array to find the maximum value and its index
  for (int i = 0; i < n; i++) {
    if (data[i] > max) {
      max = data[i];
      index = i; // Update the index of the maximum value
    }
  }

  int a = 0; // Initialize a variable to store the sum of elements excluding the maximum value

  // Iterate through the array again, excluding the element at the index of the maximum value, and sum up the remaining elements
  for (int i = 0; i < n; i++) {
    if (i!= index) {
      a += data[i];
    }
  }

  // Compare the sum of the remaining elements (a) with the maximum value (max)
  if (a > max) {
    cout << "Yes" << endl; // Print "Yes" if the sum of remaining elements is greater than the maximum value
  } else {
    cout << "No" << endl; // Print "No" otherwise
  }

  free(data); // Free the allocated memory
  return 0;
}
