
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Declare a variable to hold the weather condition input
  string S;
  
  // Read the weather condition from standard input
  cin >> S;
  
  // Use a switch statement to determine the next weather condition based on the input
  switch (S) {
  case "Sunny":
    // If the input is "Sunny", print "Cloudy" as the next condition
    cout << "Cloudy" << endl;
    break;
  case "Cloudy":
    // If the input is "Cloudy", print "Rainy" as the next condition
    cout << "Rainy" << endl;
    break;
  case "Rainy":
    // If the input is "Rainy", print "Sunny" as the next condition
    cout << "Sunny" << endl;
    break;
  }
  
  return 0;
}

