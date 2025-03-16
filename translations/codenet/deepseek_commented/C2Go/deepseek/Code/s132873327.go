package main

import (
	"fmt" // Step 1: Include necessary packages
)

func main() { // Step 2: Define the main function
	var x int // Step 3: Declare a variable

	fmt.Scan(&x) // Step 4: Read input from the user
	fmt.Println(x * x * x) // Step 5: Perform a calculation and print the result
}

