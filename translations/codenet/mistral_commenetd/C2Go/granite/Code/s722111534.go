
package main

import "fmt"

func main() {
  var hcell, wcell, hpaint, wpaint, nblack, nwhite int

  // Declare and initialize variables for the height and width of the grid,
  // the number of rows and columns to be painted with black and white respectively

  fmt.Scan(&hcell, &wcell) // Read the height and width of the grid from the user

  fmt.Scan(&hpaint, &wpaint) // Read the number of rows and columns to be painted with black and white respectively

  nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint) // Calculate the number of black painted cells

  // Calculate the number of black painted cells by multiplying the number of columns and rows to be painted with black,
  // then multiplying the height and width of the grid and subtracting the product of the number of rows and columns to be painted with black and the number of columns and rows to be painted with white

  nwhite = (hcell * wcell) - nblack // Calculate the number of white unpainted cells

  // Calculate the number of white unpainted cells by subtracting the number of black painted cells from the total number of cells in the grid

  fmt.Println(nwhite) // Print the number of white unpainted cells to the console

  // The program ends successfully with a return value of 0
}

