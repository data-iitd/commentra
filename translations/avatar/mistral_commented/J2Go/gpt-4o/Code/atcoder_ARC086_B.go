package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the first integer from the standard input
	a := make([]int, n) // Creating an integer slice of size n
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Reading integers into the slice a
	}

	var r []string // Creating an empty slice of strings to store the output
	m := 0 // Initializing the variable m to 0

	for i := 1; i < n; i++ { // Iterating through the slice a from the second element to the last one
		if math.Abs(float64(a[m])) < math.Abs(float64(a[i])) { // Comparing absolute values
			m = i // Assigning the index of the smallest absolute value to m
		}
	}

	for i := 0; i < n; i++ { // Iterating through the slice a from the first element to the last one
		if (a[m] >= 0) != (a[i] >= 0) { // Checking if the signs of the elements at indices m and i are different
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1)) // Adding the pair (m+1, i+1) to the slice r
		}
	}

	if a[m] >= 0 { // Checking if the smallest absolute value is positive
		for i := 1; i < n; i++ { // Iterating through the slice a from the second element to the last one
			r = append(r, fmt.Sprintf("%d %d", i, i+1)) // Adding the pair (i, i+1) to the slice r
		}
	} else { // If the smallest absolute value is negative
		for i := n; i > 1; i-- { // Iterating through the slice a from the last element to the second one
			r = append(r, fmt.Sprintf("%d %d", i, i-1)) // Adding the pair (i, i-1) to the slice r
		}
	}

	fmt.Println(len(r)) // Printing the size of the slice r
	for _, pair := range r { // Printing each pair in the slice r
		fmt.Println(pair)
	}
}

// <END-OF-CODE>
