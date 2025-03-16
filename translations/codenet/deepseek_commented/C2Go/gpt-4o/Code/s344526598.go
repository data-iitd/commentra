package main // Step 1: Define the main package.

import (
	"fmt" // Step 2: Import the fmt package for input/output.
)

func main() { // Step 3: Define the main function.
	var i, j int // Step 4: Declare integer variables i and j.
	x := make([]int, 10000) // Step 5: Create a slice x with a capacity of 10000.

	for i = 0; i < 10000; i++ { // Step 6: Initialize the array x with zeros (default for int).
		x[i] = 0
	}
	i = 0 // Step 7: Initialize i to 0.
	fmt.Scan(&x[i]) // Step 8: Read an integer from the input and store it in x[0].

	for x[i] != 0 { // Step 9: Use a while loop to read integers into the array x until a zero is entered.
		i++
		fmt.Scan(&x[i])
	}

	for j = 0; j < i; j++ { // Step 10: Use a for loop to print the integers stored in the array x.
		fmt.Printf("Case %d: %d\n", j+1, x[j])
	}

} // Step 11: End of the main function.

