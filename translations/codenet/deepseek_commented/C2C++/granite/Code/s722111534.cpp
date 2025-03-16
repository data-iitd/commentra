
#include<iostream>  // Include the standard input/output library

int main(){  // Define the main function, the entry point of the program
  int hcell, wcell, hpaint, wpaint, nblack, nwhite;  // Declare integer variables

  // Read the number of cells in the grid and the number of rows/columns to be painted
  std::cin >> hcell >> wcell;
  std::cin >> hpaint >> wpaint;

  // Calculate the number of black cells
  nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

  // Calculate the number of white cells
  nwhite = (hcell * wcell) - nblack;

  // Print the number of white cells
  std::cout << nwhite << std::endl;

  return 0;  // Return 0 to indicate successful execution
}
