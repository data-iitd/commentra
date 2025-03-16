package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	r := []string{}
	m := 0

	// Finding the index of the element with the maximum absolute value in the array 'a'
	for i := 1; i < n; i++ {
		if math.Abs(float64(a[m])) < math.Abs(float64(a[i])) {
			m = i
		}
	}

	// Finding pairs of indices where one element is non-negative and the other is negative
	for i := 0; i < n; i++ {
		if a[m] >= 0 != a[i] >= 0 { // Using != to check if one is non-negative and the other is negative
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1)) // Adding the operation to the ArrayList 'r'
		}
	}

	// Generating operations based on whether the maximum absolute value element is non-negative or negative
	if a[m] >= 0 {
		for i := 1; i < n; i++ {
			r = append(r, fmt.Sprintf("%d %d", i, i+1)) // Adding the operation to the ArrayList 'r'
		}
	} else {
		for i := n; i > 1; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1)) // Adding the operation to the ArrayList 'r'
		}
	}

	// Printing the number of operations and the operations themselves
	fmt.Println(len(r))
	for _, op := range r {
		fmt.Println(op)
	}
}
