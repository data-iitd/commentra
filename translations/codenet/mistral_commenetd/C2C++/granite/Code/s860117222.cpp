

#include <iostream>
// Declare three long long integers to store input values
int main (){
  long long int a, b, c;

  // Read the values of a, b, and c from the standard input using cin
  std::cin >> a >> b >> c;

  // Calculate the difference between c and the sum of a and b
  long long int d = c - a - b;

  // Check if d is positive and if the product of the squares of a and b is less than d squared
  if( d > 0 && (4 * a * b) < (d * d) )
  {
    // If the condition is true, print "Yes" to the standard output
    std::cout << "Yes" << std::endl;
  }
  else
  {
    // If the condition is false, print "No" to the standard output
    std::cout << "No" << std::endl;
  }

  // Return 0 to indicate successful execution of the program
  return 0;
}

