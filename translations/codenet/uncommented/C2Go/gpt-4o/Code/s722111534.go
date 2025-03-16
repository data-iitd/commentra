package main

import (
	"fmt"
)

func main() {
	var hcell, wcell, hpaint, wpaint int
	var nblack, nwhite int

	// Read the number of cells and the dimensions of the paint
	fmt.Scan(&hcell, &wcell)
	fmt.Scan(&hpaint, &wpaint)

	// Calculate the number of black and white cells
	nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint)
	nwhite = (hcell * wcell) - nblack

	// Print the number of white cells
	fmt.Println(nwhite)
}

// <END-OF-CODE>
