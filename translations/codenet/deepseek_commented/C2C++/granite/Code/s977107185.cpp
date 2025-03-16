
#include<iostream> // Include necessary headers for input-output functions

int main() {

  int i, j, N, A[100], tmp, count = 0; // Declare variables for loop indices, array size, array elements, temporary variable for swapping, and swap counter

  std::cin >> N; // Read the size of the array

  for(i = 0; i < N; i++) {
    std::cin >> A[i]; // Read the elements of the array
  }

  // Implement Bubble Sort
  for(i = 0; i < N - 1; i++) {
    for(j = N - 1; j > i; j--) {
      if(A[j] < A[j - 1]) {
        tmp = A[j]; // Swap A[j] and A[j-1]
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        count++; // Increment the swap counter
      }
    }
  }

  for(i = 0; i < N; i++) {
    std::cout << A[i]; // Print the sorted array elements
    if(i < N - 1) std::cout << " "; // Print a space between elements, but not after the last element
  }

  std::cout << std::endl; // Print a newline character to end the line

  std::cout << count << std::endl; // Print the number of swaps

  return 0; // Return 0 to indicate successful execution
}


