package main

import (
	"fmt"
	"sort"
)

func main() {
	// Input the number of elements (N)
	var N int
	fmt.Scan(&N)

	// Input the elements and create a slice of tuples
	A := make([]struct {
		index int
		value int
	}, N)

	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A[i] = struct {
			index int
			value int
		}{index: i + 1, value: x}
	}

	// Sort the slice of tuples based on the integer values
	sort.Slice(A, func(i, j int) bool {
		return A[i].value < A[j].value
	})

	// Extract the indices from the sorted slice of tuples
	var A_ []int
	for _, a := range A {
		A_ = append(A_, a.index)
	}

	// Print the indices in the required format
	for i := 0; i < len(A_)-1; i++ {
		fmt.Print(A_[i], " ")
	}
	fmt.Println(A_[len(A_)-1])
}

// <END-OF-CODE>
