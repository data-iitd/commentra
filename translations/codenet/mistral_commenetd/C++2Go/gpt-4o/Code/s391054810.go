package main

import (
	"fmt"
)

func main() {
	// Declare four integer variables: h, w, hh, and ww.
	var h, w, hh, ww int

	// Read four integers from the standard input and assign them to the variables h, w, hh, and ww respectively.
	fmt.Scan(&h, &w, &hh, &ww)

	// Calculate the difference between h and hh and the difference between w and ww.
	differenceH := h - hh
	differenceW := w - ww

	// Output the product of the differences to the standard output.
	fmt.Printf("The area of the rectangle is: %d\n", differenceH*differenceW)

	// Return 0 to indicate successful termination of the program.
}
