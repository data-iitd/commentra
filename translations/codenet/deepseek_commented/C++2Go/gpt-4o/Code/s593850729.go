package main // Declare the main package

import (
	"fmt" // Import the fmt package for input and output
)

func main() { // The main function is the entry point of the program
	var A, B, C, X int // Declare variables to store the input values
	fmt.Scan(&A, &B, &C, &X) // Read the values of A, B, C, and X from standard input

	cnt := 0 // Initialize a counter to count the number of combinations
	for a := 0; a <= A; a++ { // Iterate over the possible values of a (0 to A)
		for b := 0; b <= B; b++ { // Iterate over the possible values of b (0 to B)
			for c := 0; c <= C; c++ { // Iterate over the possible values of c (0 to C)
				total := 500*a + 100*b + 50*c // Calculate the total value of the coins
				if total == X { // If the total equals X, increment the counter
					cnt++
				}
			}
		}
	}
	fmt.Println(cnt) // Output the number of combinations that sum up to X
}

// <END-OF-CODE>
