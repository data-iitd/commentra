package main

import (
	"fmt"
	"os"
)

func main() {
	// Set the standard input to be read from the provided input stream
	var n int
	fmt.Fscan(os.Stdin, &n)

	// Initialize a slice to store the given numbers
	w := make([]int, n)

	// Read the given numbers and store them in the slice
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &w[i])
	}

	// Initialize a variable 'c' with a value of 2
	c := 2

	// Iterate through each number in the slice 'w'
	for _, number := range w {
		// If the number is equal to 1, print the current value of 'c'
		if number == 1 {
			fmt.Println(c)
		} else if number%2 == 0 { // If the number is even, toggle the value of 'c'
			c = 3 - c
			fmt.Println(c)
		} else { // If the number is odd, print the current value of 'c'
			fmt.Println(c)
		}
	}
}

// <END-OF-CODE>
