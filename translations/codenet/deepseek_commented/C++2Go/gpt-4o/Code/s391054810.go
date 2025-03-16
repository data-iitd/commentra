package main

import (
	"fmt"
)

func main() {
	// Declare integer variables to store input values
	var h, w, hh, ww int
	
	// Read values from the standard input and store them in the variables
	fmt.Scan(&h, &w, &hh, &ww)
	
	// Perform arithmetic operation to calculate the area of a rectangle
	// Output the result to the standard output
	fmt.Println((h - hh) * (w - ww))
}

// Indicate that the program ended successfully
// <END-OF-CODE>
