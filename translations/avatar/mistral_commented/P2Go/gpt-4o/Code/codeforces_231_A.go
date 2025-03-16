package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take an integer 'n' as input from the user
	var n int
	fmt.Scan(&n)

	// Initialize a counter 'c' to 0
	c := 0

	// Iterate through the range of 'n'
	for i := 0; i < n; i++ {
		// Take 'n' lists of integers as input from the user
		var input string
		fmt.Scan(&input)

		// Split the input string into a slice of strings
		strs := strings.Split(input, " ")
		sum := 0

		// Convert each string to an integer and calculate the sum
		for _, str := range strs {
			num, _ := strconv.Atoi(str)
			sum += num
		}

		// Check if the sum of the elements in the current list is greater than 1
		if sum > 1 {
			// Increment the counter 'c' by 1 if the condition is true
			c++
		}
	}

	// Print the value of the counter 'c'
	fmt.Println(c)
}

// <END-OF-CODE>
