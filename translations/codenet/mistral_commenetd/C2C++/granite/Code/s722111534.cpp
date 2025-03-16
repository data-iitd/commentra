
#include<iostream> // We include the standard input/output library

int main(){ // The main function is the starting point of the program
  int hcell, wcell, hpaint, wpaint, nblack, nwhite; // Declare variables

  // Declare and initialize variables for the height and width of the grid,
  // the number of rows and columns to be painted with black and white respectively

  std::cin >> hcell >> wcell; // Read the height and width of the grid from the user

  std::cin >> hpaint >> wpaint; // Read the number of rows and columns to be painted with black and white respectively

  nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint); // Calculate the number of black painted cells

  // Calculate the number of black painted cells by multiplying the number of columns and rows to be painted with black,
  // then multiplying the height and width of the grid and subtracting the product of the number of rows and columns to be painted with black and the number of columns and rows to be painted with white

  nwhite = (hcell*wcell) - nblack; // Calculate the number of white unpainted cells

  // Calculate the number of white unpainted cells by subtracting the number of black painted cells from the total number of cells in the grid

  std::cout << nwhite << std::endl; // Print the number of white unpainted cells to the console

  return 0; // The program ends successfully with a return value of 0
}

