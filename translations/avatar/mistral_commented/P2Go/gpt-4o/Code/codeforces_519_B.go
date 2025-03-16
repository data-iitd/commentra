package main

import (
	"fmt"
	"math"
)

func main() {
	// Take the number of test cases as input
	var n int
	fmt.Scan(&n)

	// Read the first list 'a' of numbers from the standard input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Read the second list 'b' of numbers from the standard input
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}

	// Read the third list 'c' of numbers from the standard input
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}

	// Initialize variables x, y, and z to 0
	x, y, z := 0, 0, 0

	// Iterate through each number in list 'a' and add it to the variable 'x'
	for _, value := range a {
		x += value
	}

	// Iterate through each number in list 'b' and add it to the variable 'y'
	for _, value := range b {
		y += value
	}

	// Iterate through each number in list 'c' and add it to the variable 'z'
	for _, value := range c {
		z += value
	}

	// Print the absolute difference between 'x' and 'y'
	fmt.Println(int(math.Abs(float64(x - y))))

	// Print the absolute difference between 'y' and 'z'
	fmt.Println(int(math.Abs(float64(y - z))))
}

// <END-OF-CODE>
