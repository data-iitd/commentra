package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take the number of elements as input
	var N int
	fmt.Scan(&N)

	// Take a space-separated string of integers as input and convert them to a slice of integers
	var input string
	fmt.Scan(&input)
	nStr := strings.Split(input, " ")
	n := make([]int, N)
	for i := 0; i < N; i++ {
		n[i], _ = strconv.Atoi(nStr[i])
	}

	// Initialize a counter to 1 and a position index to 0
	a := 1
	pos := 0

	// Loop through the slice from the second element to the last
	for i := 1; i < N; i++ {
		// Check if the current minimum element is greater than the current element
		if n[pos] > n[i] {
			// Increment the counter and update the position index
			a++
			pos = i
		}
	}

	// Print the final count of elements that are greater than the current minimum
	fmt.Println(a)
}

// <END-OF-CODE>
