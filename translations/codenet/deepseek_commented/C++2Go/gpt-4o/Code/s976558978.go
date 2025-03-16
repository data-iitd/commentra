package main

import (
	"fmt"
	"os"
)

func main() {
	// Allow local testing with a specific file
	file, err := os.Open("dataabc155A.txt")
	if err != nil {
		file = os.Stdin
	}
	defer file.Close()

	var a, b int
	fmt.Fscanf(file, "%d", &a) // Read integer a
	fmt.Fscanf(file, "%d", &b) // Read integer b

	if a < b { // Check if a is less than b
		for i := 0; i < b; i++ {
			fmt.Print(a) // Print a b times
		}
		fmt.Println() // New line
	} else { // Otherwise
		for i := 0; i < a; i++ {
			fmt.Print(b) // Print b a times
		}
		fmt.Println() // New line
	}
}

// <END-OF-CODE>
