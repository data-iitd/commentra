package main

import (
	"fmt"
	"math"
)

func main() {
	// Read an integer input which represents the number of elements in the lists
	var n int
	fmt.Scan(&n)

	// Read three lists of integers from input
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}

	// Initialize variables to hold the sum of each list
	x, y, z := 0, 0, 0

	// Calculate the sum of elements in list 'a'
	for _, value := range a {
		x += value
	}

	// Calculate the sum of elements in list 'b'
	for _, value := range b {
		y += value
	}

	// Calculate the sum of elements in list 'c'
	for _, value := range c {
		z += value
	}

	// Print the absolute difference between the sums of list 'a' and list 'b'
	fmt.Println(int(math.Abs(float64(x - y))))

	// Print the absolute difference between the sums of list 'b' and list 'c'
	fmt.Println(int(math.Abs(float64(y - z))))
}

// <END-OF-CODE>
