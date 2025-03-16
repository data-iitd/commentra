
#include<iostream>

int main()
{
  // Declare variables
  int i, j, N, A[100], tmp, count = 0;

  // Read the number of elements to be sorted
  std::cin >> N;

  // Input the elements into the array A
  for(i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  // Perform bubble sort on the array A
  for(i = 0; i < N - 1; i++) {
    for(j = N - 1; j > i; j--) {
      // Compare adjacent elements and swap if they are in the wrong order
      if(A[j] < A[j - 1]) {
        tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;

        // Increment the swap count
        count++;
      }
    }
  }

  // Output the sorted array
  for(i = 0; i < N; i++) {
    std::cout << A[i];

    // Print a space between elements, but not after the last element
    if(i < N - 1) std::cout << " ";
  }

  // Print a newline after the sorted array
  std::cout << std::endl;

  // Print the total number of swaps made during sorting
  std::cout << count << std::endl;

  return 0;
}


