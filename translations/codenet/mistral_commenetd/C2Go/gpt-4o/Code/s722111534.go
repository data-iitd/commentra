package main // We declare the main package

import (
	"fmt" // We import the fmt package for formatted I/O
)

func main() { // The main function is the starting point of the program
	var hcell, wcell, hpaint, wpaint, nblack, nwhite int // Declare variables

	// Read the height and width of the grid from the user
	fmt.Scanf("%d %d", &hcell, &wcell)

	// Read the number of rows and columns to be painted with black and white respectively
	fmt.Scanf("%d %d", &hpaint, &wpaint)

	// Calculate the number of black painted cells
	nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint)

	// Calculate the number of white unpainted cells
	nwhite = (hcell * wcell) - nblack

	// Print the number of white unpainted cells to the console
	fmt.Println(nwhite)
}

// The program ends successfully
