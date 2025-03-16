package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	var x []int
	var m, q int

	// Read the elements of the list from input and split them into individual strings
	var input string
	fmt.Scan(&input)
	elements := strings.Split(input, " ")

	// Convert the list of strings into a list of integers
	for _, element := range elements {
		num, _ := strconv.Atoi(element)
		x = append(x, num)
	}

	// Iterate through the list to compare adjacent elements
	for a := 0; a < len(x)-1; a++ {
		// Check if the current element is greater than or equal to the next element
		if x[a] >= x[a+1] {
			// Calculate how many increments of d are needed to make x[a+1] greater than x[a]
			q = (x[a] - x[a+1]) / d + 1
			// Update the total adjustments made
			m = m + q
			// Adjust the next element by adding the necessary increments of d
			x[a+1] = x[a+1] + q*d
		}
	}

	// Print the total number of adjustments made
	fmt.Println(m)
}
