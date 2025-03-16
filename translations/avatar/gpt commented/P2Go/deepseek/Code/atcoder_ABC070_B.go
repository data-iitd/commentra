package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input, split it into components, and convert each component to an integer, storing them in a list A
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	A := make([]int, len(parts))
	for i, part := range parts {
		A[i], _ = strconv.Atoi(part)
	}

	// Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
	if A[1] <= A[2] || A[3] <= A[0] {
		// If the condition is true, print 0
		fmt.Println(0)
	} else {
		// If the condition is false, sort the list A in ascending order
		sort.Ints(A)
		// Calculate the difference between the largest and the second largest elements in the sorted list and print the result
		fmt.Println(A[2] - A[1])
	}
}

