
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  // Step 1: Include necessary headers
  // The code starts by including necessary headers for input/output operations,
  // string manipulation, and using standard namespace.
  string W;
  cin >> W;
  
  // Step 2: Read input
  // The program reads a string `W` from the standard input.
  
  // Step 3: Sort the string
  // The string `W` is sorted in ascending order.
  sort(W.begin(),W.end());

  // Step 4: Check for character pairs
  // The program iterates through the sorted string, checking if each character
  // is followed by its identical pair.
  for (string::iterator itr = W.begin(); itr != W.end(); itr+=2)
  {
    if(*itr != *(itr+1))
    {
      // If a character is not followed by its pair, output "No" and exit.
      cout << "No" << endl;
      return 0;
    }
    
  }
  
  // Step 5: Output result
  // If all characters are in pairs, the program outputs "Yes"; otherwise,
  // it outputs "No".
  cout << "Yes" << endl;
  
  return 0;
}

