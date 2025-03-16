#include <iostream>

// The main function is the entry point of the program
int main(){
  // Declare variables
  int key, i, j, len, a[101];

  // Read the length of the array from the user
  std::cout << "Enter the length of the array: ";
  std::cin >> len;

  // Read the elements of the array from the user
  std::cout << "Enter " << len << " integers: ";
  for(i = 0;i < len;i++) {
    std::cin >> a[i];
  }

  // Sort the array using bubble sort algorithm
  for(j = 1;j < len;j++){
    // Iterate through the array and compare each element with the current key
    for(i = 0;i < len;i++) {
      // If the current element is not the first one, print it with a space
      if(i != 0) std::cout << " " << a[i];
      // Otherwise, print it without a space
      else std::cout << a[i];
    }
    // Print a new line after each pass
    std::cout << std::endl;

    // Set the current key to the next element
    key = a[j];

    // Swap the current key with the previous element if it is greater
    for(i = j - 1;i >= 0 && a[i] > key;i--) {
      a[i + 1] = a[i];
    }

    // Swap the current key with the previous element
    a[i + 1] = key;
  }

  // Print the sorted array
  for(i = 0;i < len;i++) {
    // If the current index is not the first one, print it with a space
    if(i != 0) std::cout << " " << a[i];
    // Otherwise, print it without a space
    else std::cout << a[i];
  }
  // Print a new line after printing the sorted array
  std::cout << std::endl;

  // Return 0 to indicate successful execution
  return 0;
}

