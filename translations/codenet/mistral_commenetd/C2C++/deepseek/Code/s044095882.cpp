#include <iostream>
using namespace std;

int main() {
  long int n; // Declare a variable to store the number of elements in the array

  cout << "Enter the number of elements: ";
  cin >> n; // Read the number of elements from the standard input and store it in n

  long int* a = new long int[n]; // Declare a dynamic array of size n to store the input numbers
  long int* count = new long int[n]; // Declare a dynamic array of size n to store the count of occurrences of each number

  cout << "Enter " << n << " numbers:\n";
  for (long int i = 0; i < n; i++) { // Initialize the array a with input numbers
    cin >> a[i];
  }

  cout << "Initializing count array with zeros:\n";
  for (long int i = 0; i < n; i++) { // Initialize all elements of the count array to zero
    count[i] = 0;
  }

  cout << "Counting occurrences:\n";
  for (long int i = 0; i < n; i++) { // Iterate through the array a and increment the corresponding element in the count array
    count[a[i]-1]++;
  }

  cout << "Printing the contents of the count array:\n";
  for (long int i = 0; i < n; i++) { // Print the contents of the count array to the standard output
    cout << count[i] << endl;
  }

  cout << "Program completed successfully." << endl;
  delete[] a; // Free the dynamically allocated memory for array a
  delete[] count; // Free the dynamically allocated memory for array count
  return 0; // Return 0 to indicate successful termination
}

