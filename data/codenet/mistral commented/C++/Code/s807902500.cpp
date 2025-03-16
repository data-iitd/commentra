
#include <iostream>
// Include the iostream library and use the standard namespace.
using namespace std;

int main() {
  // Declare two string variables s and t to store user input.
  string s, t;

  // Read user input and store it in variables s and t respectively.
  cin>>s>>t;

  // Concatenate the string s with itself and store the result back in s.
  s+=s;

  // Use the puts() function to print the result to the console.
  puts(s.find(t)!=string::npos?"Yes":"No");
  // Check if the substring t is present in the string s. If it is, print "Yes" to the console. Otherwise, print "No".

  return 0;
}