#include<iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace for easier access to iostream functions

int main(){ // Start of the main function
  int n; // Declare an integer variable 'n' to store the size of the array
  int a[101]; // Declare an integer array 'a' of size 101
  int i; // Declare an integer variable 'i' as a counter

  cin >> n; // Read the size of the array from the user input

  // Allocate memory for the array 'a' of size 'n'
  for(i=0; i<n;i++)
  {
    cin >> a[i]; // Read each element of the array 'a' from the user input
  }

  // Print the last element of the array
  cout << a[n-1];

  // Print the remaining elements of the array in reverse order
  for(i=1;i<n;i++)
  {
    cout<< " " << a[n-i-1]; // Print the current element with a space before it
  }

  cout << endl; // Print a newline character at the end

  return 0; // Indicate successful termination of the program
}