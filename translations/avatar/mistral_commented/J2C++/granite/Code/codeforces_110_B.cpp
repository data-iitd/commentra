

#include <iostream> // Include the standard input/output stream objects
#include <cstdio> // Include the standard input/output stream functions

using namespace std; // Use the standard namespace

int main ( ) {
  int n ; // Declare an integer variable `n` to store the size of the character array
  int i, j ; // Declare two integer variables `i` and `j` to use as loop counters
  char c [ ] ; // Declare a character array `c` of size `n`
  char p = 'a' ; // Declare a character variable `p` to store the current character to be added to the array

  cin >> n ; // Read an integer `n` from the standard input using the cin object
  c = new char [ n ] ; // Create a new character array `c` of size `n`

  for ( i = 0 ; i < 4 ; i ++ ) { // Use a for loop to iterate through the first four elements of the array
    for ( j = i ; j < n ; j += 4 ) { // Use a nested for loop to populate every fourth element of the array with the next character
      c [ j ] = p ; // Set the current element of the array to the current character
      p ++ ; // Increment the character to be added to the next element
    }
  }

  for ( i = 0 ; i < n ; i ++ ) { // Use a for loop to print each character in the array to the standard output
    cout << c [ i ] ; // Print the current character to the standard output using the cout object
  }

  delete [ ] c ; // Deallocate the memory used by the character array `c`

  return 0 ; // Return 0 to indicate successful program execution
}

