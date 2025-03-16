

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize the variable `c` to 2
	c := 2

	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the list `w`
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Read the list of integers `w`
	w := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		w[i], _ = strconv.Atoi(scanner.Text())
	}

	// Loop through each element `i` in the list `w`
	for _, i := range w {
		// Check if `i` is equal to 1
		if i == 1 {
			// Print the current value of `c`
			fmt.Println(c)
		}
		// Check if `i` is even
		else if i%2 == 0 {
			// Toggle the value of `c` between 2 and 3-c (i.e., 1 or 3)
			c = 3 - c
			// Print the new value of `c`
			fmt.Println(c)
		}
		// If `i` is odd
		else {
			// Print the current value of `c`
			fmt.Println(c)
		}
	}
}
