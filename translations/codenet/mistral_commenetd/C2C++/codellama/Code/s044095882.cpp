
#include <iostream>

int main() {
  long int n; // Declare a variable to store the number of elements in the array

  std::cout << "Enter the number of elements: ";
  std::cin >> n; // Read the number of elements from the standard input and store it in n

  long int a[n]; // Declare an array of size n to store the input numbers
  long int count[n]; // Declare an array of size n to store the count of occurrences of each number

  std::cout << "Enter " << n << " numbers:\n";
  for (long int i = 0; i < n; i++) { // Initialize the array a with input numbers
    std::cin >> a[i];
  }

  std::cout << "Initializing count array with zeros:\n";
  for (long int i = 0; i < n; i++) { // Initialize all elements of the count array to zero
    count[i] = 0;
  }

  std::cout << "Counting occurrences:\n";
  for (long int i = 0; i < n; i++) { // Iterate through the array a and increment the corresponding element in the count array
    count[a[i]-1]++;
  }

  std::cout << "Printing the contents of the count array:\n";
  for (long int i = 0; i < n; i++) { // Print the contents of the count array to the standard output
    std::cout << count[i] << "\n";
  }

  std::cout << "Program completed successfully.\n";
  return 0; // Return 0 to indicate successful termination
}

