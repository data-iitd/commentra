package main // Step 1: Declare the main package.

import (
	"fmt" // Step 2: Import the necessary package for input and output.
)

func main() {
	var N, A int // Step 3: Declare the necessary variables.
	fmt.Scan(&N) // Step 4: Read the input values.
	fmt.Scan(&A)
	fmt.Println(N*N - A) // Step 5: Perform the required calculations and output the result.
} // <END-OF-CODE>
