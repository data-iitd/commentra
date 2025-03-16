package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func s() string {
	// Read an input line (not used in the logic)
	fmt.Scanln()

	// Read a line of integers, split by spaces, and convert them to a list of integers
	a := strings.Split(fmt.Scanln(), " ")
	for i := 0; i < len(a); i++ {
		a[i], _ = strconv.Atoi(a[i])
	}

	// Sort the list of integers in ascending order
	sort.Ints(a)

	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is different from the previous one
		// and if it is less than double the previous element
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, return 'YES'
			return "YES"
		}
	}

	// If no such pair is found, return 'NO'
	return "NO"
}

// Call the function and print the result
fmt.Println(s())

