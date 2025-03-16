package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a vector to store the elements
	a := make([]int, n)

	// Input the elements into the vector
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the answer counter and a flag for the loop
	ans := 0
	ok := true

	// Loop until an odd number is found in the vector
	for ok {
		// Check each element in the vector
		for i := 0; i < n; i++ {
			// If the current element is odd, print the answer and exit
			if a[i]%2 == 1 {
				fmt.Println(ans)
				return
			}
			// If the current element is even, divide it by 2
			else {
				a[i] /= 2
			}
		}
		// Increment the answer counter for each complete iteration
		ans++
	}

	// Output the final count of divisions by 2 before encountering an odd number
	fmt.Println(ans)
}

