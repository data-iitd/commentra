
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  string W; // Declare a string variable named W to store the input word

  // Read the input word from the standard input stream using cin
  cin >> W;

  // Sort the characters in the string W in ascending order using the sort function from the <algorithm> library
  sort(W.begin(),W.end());

  // Initialize a string iterator named itr to point to the first character in the sorted string W
  string::iterator itr = W.begin();

  // Loop through the sorted string W using a for loop, with the loop condition that itr does not point to the end of the string
  for (; itr != W.end(); itr++)
  {
    // Check if the current character and the next character in the string are the same
    if(*itr != *(itr+1))
    {
      // If they are not the same, print "No" to the standard output stream and return from the main function
      cout << "No" << endl;
      return 0;
    }
  }

  // If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
  cout << "Yes" << endl;

  // Return 0 to indicate successful execution of the main function
  return 0;
}

