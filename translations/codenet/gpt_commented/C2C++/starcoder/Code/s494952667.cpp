#include <iostream>
#include <string>

using namespace std;

int main()
{
  // Declare a string object to hold the input string
  string str;
  int i, len;
  
  // Read a string from standard input
  cin >> str;
  
  // Calculate the length of the input string
  len = str.length();

  // Loop through the string in reverse order
  for(i = len - 1; i >= 0; i--){
    // Output each character of the string in reverse
    cout << str[i];
  }
  
  // Print a newline character after the reversed string
  cout << endl;
  
  // Return 0 to indicate successful completion of the program
  return 0;
}

