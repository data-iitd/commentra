
#include <iostream>
using namespace std;

int main() {
  // Declare a variable to hold the input string
  string s;
  
  // Read input from the user and store it in the variable 's'
  cin >> s;
  
  // Check if the first three characters are the same or the last three characters are the same
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]) {
    // If the condition is true, print "Yes"
    cout << "Yes" << endl;
  } else {
    // If the condition is false, print "No"
    cout << "No" << endl;
  }
  
  return 0;
}

