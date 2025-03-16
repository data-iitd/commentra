package main // Define the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function, the entry point of the program
	var hcell, wcell, hpaint, wpaint, nblack, nwhite int // Declare integer variables

	// Read the number of cells in the grid and the number of rows/columns to be painted
	fmt.Scan(&hcell, &wcell)
	fmt.Scan(&hpaint, &wpaint)

	// Calculate the number of black cells
	nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

	// Calculate the number of white cells
	nwhite = (hcell * wcell) - nblack

	// Print the number of white cells
	fmt.Println(nwhite)
}

// <END-OF-CODE>
