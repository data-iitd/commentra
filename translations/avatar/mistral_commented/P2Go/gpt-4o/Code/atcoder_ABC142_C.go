package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Define the number of elements in the list 'A'
	var N int
	fmt.Scan(&N)

	// Initialize a slice of tuples (index, value)
	A := make([][2]int, N)

	// Read the input values and populate the slice
	var input string
	fmt.Scan(&input)
	values := strings.Split(input, " ")
	for i := 0; i < N; i++ {
		value, _ := strconv.Atoi(values[i])
		A[i] = [2]int{i + 1, value}
	}

	// Sort the slice 'A' based on the second element of each tuple (the value)
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first element (index) of each tuple in 'A' into a new slice 'A__'
	A__ := make([]int, N)
	for i := 0; i < N; i++ {
		A__[i] = A[i][0]
	}

	// Iterate through the slice 'A__' (excluding the last element) and print each index
	for i := 0; i < N-1; i++ {
		fmt.Print(A__[i], " ")
	}

	// Print the last index in 'A__'
	fmt.Println(A__[N-1])
}

// <END-OF-CODE>
