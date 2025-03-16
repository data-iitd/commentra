#include <iostream>
using namespace std;

int main() {
  // Declare a string variable S to store the weather input
  string S;
  
  // Read a string input from the user and store it in S
  cin >> S;
  
  // Use a switch statement to determine the weather based on the input
  switch (S) {
  case "Sunny" : 
    // If the input is "Sunny", print "Cloudy"
    cout << "Cloudy" << endl;
  case "Cloudy" : 
    // If the input is "Cloudy", print "Rainy"
    cout << "Rainy" << endl;
  case "Rainy" : 
    // If the input is "Rainy", print "Sunny"
    cout << "Sunny" << endl;
  }
  
  return 0;
}

