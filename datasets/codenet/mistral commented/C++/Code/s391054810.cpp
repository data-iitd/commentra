
#include <iostream>

// Declare four integer variables: h, w, hh, and ww.
int h, w, hh, ww;

int main()
{
  // Read four integers from the standard input and assign them to the variables h, w, hh, and ww respectively.
  std::cin >> h >> w >> hh >> ww;

  // Calculate the difference between h and hh and the difference between w and ww.
  int difference_h = h - hh;
  int difference_w = w - ww;

  // Output the product of the differences to the standard output.
  std::cout << "The area of the rectangle is: " << difference_h * difference_w << '\n';

  // Return 0 to indicate successful termination of the program.
  return 0;
}