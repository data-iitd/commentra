#include <iostream>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t; // Read two strings from standard input

  // Concatenate s with itself to double its length
  s += s;

  // Check if t is a substring of the doubled s
  // If found, find returns the position; otherwise, it returns string::npos
  // Convert the result to a boolean for easy printing
  puts((s.find(t) != string::npos) ? "Yes" : "No");
}
