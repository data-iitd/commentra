#include <iostream>
using namespace std;

int main() {
  // Declare a variable to store the input string
  string s;
  
  // Read a string input from the user and store it in `s`
  cin >> s;
  
  // Check if the first three characters of `s` are the same or if the second three characters of `s` are the same
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]){
    // If either condition is true, print "Yes"
    cout << "Yes" << endl;
  } else {
    // Otherwise, print "No"
    cout << "No" << endl;
  }
  
  // End of code
  return 0;
}