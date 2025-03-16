package main

import "fmt"

func main() {
	// Read three integers from input: n (number of elements), a, and b
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	// Read a list of integers from input and store it in lista
	lista := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lista[i])
	}

	// Read another list of integers from input and store it in listb
	listb := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&listb[i])
	}

	// Iterate through the range of n (from 0 to n-1)
	for k := 0; k < n; k++ {
		// Check if the current index + 1 is present in lista
		if lista[k] == k+1 {
			// If present, print 1 followed by a space
			fmt.Printf("1 ")
		} else {
			// If not present, print 2 followed by a space
			fmt.Printf("2 ")
		}
	}
}

