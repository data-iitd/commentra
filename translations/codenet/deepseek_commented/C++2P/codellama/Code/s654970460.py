#include<iostream>  # Include the necessary header files for input and output operations.
using namespace std;  # Use the standard namespace to avoid prefixing standard library names with 'std::'.

int main():  # Define the main function which is the entry point of the program.
  int n, a[101], i;  # Declare an integer variable 'n' to store the number of elements, an array 'a' of size 101, and an integer variable 'i' for looping.
  cin >> n;  # Input the number of elements for the array 'a'.
  for(i = 0; i < n; i++):  # Loop to take 'n' integer inputs and store them in the array 'a'.
    cin >> a[i];
  cout << a[n-1];  # Output the last element of the array 'a'.
  for(i = 1; i < n; i++):  # Loop to output the remaining elements of the array 'a' in reverse order.
    cout << " " << a[n-i-1];
  cout << endl;  # End the line after outputting all the elements.
  return 0;  # Return 0 to indicate successful execution.


