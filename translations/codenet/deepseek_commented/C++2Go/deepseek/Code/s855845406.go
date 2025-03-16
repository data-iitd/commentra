package main

import (
	"fmt" // Step 1: Include the necessary package.
)

func main() {
	var N, A int // Step 2: Declare the necessary variables.
	fmt.Scan(&N) // Step 3: Read the input values.
	fmt.Scan(&A)
	fmt.Println(N*N - A) // Step 4: Perform the required calculations.
                        // Step 5: Output the result.
}

