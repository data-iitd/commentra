
#include <iostream>

int main(void){

  int S; // Declare an integer variable named S

  // Read an integer value from the standard input using cin function
  std::cin >> S;

  // Check if the value of S is less than 60
  if (S < 60)
    {
      // If the condition is true, print the time in the format "0:0:S"
      std::cout << "0:0:" << S << std::endl;
    }

  // Else if the value of S is less than 3600 (1 hour)
  else if (S < 3600)
    {
      // Calculate the number of hours by dividing the value of S by 60
      // Print the time in the format "0:M:S"
      std::cout << "0:" << (int)S/60 << ":" << S%60 << std::endl;
    }

  // Else if the value of S is greater than or equal to 3600
  else
    {
      // Calculate the number of hours by dividing the value of S by 3600
      // Calculate the number of minutes by finding the remainder of S when divided by 60
      // Calculate the number of seconds by finding the remainder of the remainder when divided by 60
      // Print the time in the format "H:M:S"
      std::cout << (int)S/3600 << ":" << (int)(S%3600)/60 << ":" << (S%60)%60 << std::endl;
    }

  // Return 0 to indicate successful execution of the program
  return 0;
}
