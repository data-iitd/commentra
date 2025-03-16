#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  // Declare a string variable to hold the input
  string W;
  
  // Read input string from the user
  cin >> W;
  
  // Sort the characters in the string in ascending order
  sort(W.begin(), W.end());

  // Iterate through the sorted string, checking pairs of characters
  for (string::iterator itr = W.begin(); itr != W.end(); itr += 2)
  {
    // Check if the current character is not equal to the next character
    if (*itr != *(itr + 1))
    {
      // If they are not equal, print "No" and exit the program
      cout << "No" << endl;
      return 0;
    }
  }
  
  // If all pairs are equal, print "Yes"
  cout << "Yes" << endl;

  // Return 0 to indicate successful completion of the program
  return 0;
}
