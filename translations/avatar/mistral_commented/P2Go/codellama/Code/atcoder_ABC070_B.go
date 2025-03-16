package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Create a list 'A' from the input, which is a sequence of space-separated integers
	A := strings.Split(strings.TrimSpace(input()), " ")

	// Check if the second or third element of the list 'A' is less than or equal to the first element
	if A[1] <= A[2] || A[3] <= A[0] {
		// If the condition is true, print '0'
		fmt.Println(0)
	} else {
		// If the condition is false, sort the list 'A' in ascending order
		sort.Slice(A, func(i, j int) bool {
			return strconv.Atoi(A[i]) < strconv.Atoi(A[j])
		})

		// Print the difference between the third and second elements of the sorted list
		fmt.Println(strconv.Atoi(A[2]) - strconv.Atoi(A[1]))
	}
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

