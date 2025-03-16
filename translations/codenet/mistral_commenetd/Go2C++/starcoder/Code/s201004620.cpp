// C++ program to check the weather condition
#include <iostream>
using namespace std;

// Function to check the weather condition
void checkWeather(string S){
  // Switch statement to check the value of the string S and print the corresponding weather condition
  switch (S) {
  case "Sunny" : // If the input string is "Sunny"
    cout << "Cloudy" << endl; // Print "Cloudy" as the output
  case "Cloudy" : // If the input string is "Cloudy"
    cout << "Rainy" << endl; // Print "Rainy" as the output
    case "Rainy" : // If the input string is "Rainy"
      cout << "Sunny" << endl; // Print "Sunny" as the output
  }
}

// Driver code
int main()
{
  // Declare a variable named S of type string
  string S;

  // Read a string input from the standard input using cin
  cin >> S;

  // Function call to check the weather condition
  checkWeather(S);

  return 0;
}

// End of the code

