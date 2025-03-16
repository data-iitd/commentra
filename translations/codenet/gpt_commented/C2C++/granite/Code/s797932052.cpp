
#include<iostream>

int main(void)
{
  // Declare two integer variables to hold user input
  int a, b;

  // Read the first integer from user input
  std::cin >> a;
  
  // Read the second integer from user input
  std::cin >> b;
  
  // Check if the product of a and b is even
  if((a * b) % 2 == 0) {
    // If the product is even, print "Even"
    std::cout << "Even\n";
  } else {
    // If the product is odd, print "Odd"
    std::cout << "Odd\n";
  }
  
  // Return 0 to indicate successful completion of the program
  return 0;
}
