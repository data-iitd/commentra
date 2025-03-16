package main

import (
	"fmt"
	"os"
)

func main() {
	// Use bufio for faster input reading
	var n int
	fmt.Fscan(os.Stdin, &n)

	// Read the list of integers from input
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &w[i])
	}

	// Initialize a variable 'c' to track the output state
	c := 2

	// Iterate through each element in the list 'w'
	for _, i := range w {
		// If the current element is 1, print the current value of 'c'
		if i == 1 {
			fmt.Println(c)
		} else if i%2 == 0 { // If the current element is even
			c = 3 - c // This will switch c between 2 and 3
			fmt.Println(c)
		} else { // If the current element is odd (and not 1)
			fmt.Println(c)
		}
	}
}

// <END-OF-CODE>
