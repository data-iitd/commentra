#include <iostream> // Include headers for input/output operations
#include <string>   // Include headers for string manipulation

using namespace std; // Use the standard namespace

int main()
{
  string str; // Declare a string to store the input string
  int i, len; // Declare loop counters
  
  cin >> str; // Read a string from the user
  
  len = str.length(); // Calculate the length of the input string

  // Reverse the string and print it
  for(i = len - 1; i >= 0; i--) {
    cout << str[i]; // Print each character in reverse order
  }
  cout << endl; // Print a newline character at the end
  
  return 0; // Return 0 to indicate successful execution
}

