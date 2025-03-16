#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main() {
  string s, t; // Declare two string variables, s and t
  cin >> s >> t; // Read input strings s and t from the user

  s += s; // Concatenate string s with itself, effectively doubling it

  // Check if string t can be found within the doubled string s
  // If found, print "Yes", otherwise print "No"
  puts(s.find(t) + 1 ? "Yes" : "No");
}

