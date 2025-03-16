
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the list of integers from input
	var w []int
	fmt.Scan(&w)

	// Initialize a variable 'c' to track the output state
	c := 2

	// Iterate through each element in the list 'w'
	for _, i := range w {
		// If the current element is 1, print the current value of 'c'
		if i == 1 {
			fmt.Println(c)
		}
		// If the current element is even, toggle 'c' between 2 and 3
		if i%2 == 0 {
			c = 3 - c // This will switch c between 2 and 3
			fmt.Println(c)
		}
		// If the current element is odd (and not 1), print the current value of 'c'
		if i%2 != 0 {
			fmt.Println(c)
		}
	}
}

