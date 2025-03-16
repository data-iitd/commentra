
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

	// Read the list of integers
	var w []int
	fmt.Scan(&w)

	// Calculate the sum of the list
	var x int
	for _, v := range w {
		x += v
	}

	// Initialize an empty list to store indices
	var d []int

	// Iterate through each element in the list
	for i := 0; i < n; i++ {
		// Check if removing the current element results in an average equal to the current element
		if (x - w[i])/int(n-1) == w[i] {
			// If the condition is met, append the 1-based index to the list
			d = append(d, i+1)
		}
	}

	// Print the number of valid indices found
	fmt.Println(len(d))

	// Print the valid indices as a space-separated string
	fmt.Println(strings.Join(strings.Fields(fmt.Sprint(d)), " "))
}

