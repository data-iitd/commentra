package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read input from the user
	var input string
	fmt.Scanln(&input)

	// Split the input string into a slice of strings
	elements := strings.Split(input, " ")

	// Convert the slice of strings to a slice of integers
	A := make([]int, len(elements))
	for i, elem := range elements {
		A[i], _ = strconv.Atoi(elem)
	}

	// Check if the second or third element of the list 'A' is less than or equal to the first element
	if A[1] <= A[2] || A[3] <= A[0] {
		// If the condition is true, print '0'
		fmt.Println(0)
	} else {
		// If the condition is false, sort the list 'A' in ascending order
		sort.Ints(A)

		// Print the difference between the third and second elements of the sorted list
		fmt.Println(A[2] - A[1])
	}
}

