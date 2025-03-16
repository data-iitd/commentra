#include <iostream>

int main() {
  // Declare a variable to hold the weather condition input
  std::string S;
  
  // Read the weather condition from standard input
  std::cin >> S;
  
  // Use a switch statement to determine the next weather condition based on the input
  switch (S) {
  case "Sunny":
    // If the input is "Sunny", print "Cloudy" as the next condition
    std::cout << "Cloudy" << std::endl;
    break;
  case "Cloudy":
    // If the input is "Cloudy", print "Rainy" as the next condition
    std::cout << "Rainy" << std::endl;
    break;
  case "Rainy":
    // If the input is "Rainy", print "Sunny" as the next condition
    std::cout << "Sunny" << std::endl;
    break;
  }
}

