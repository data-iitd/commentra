package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in each list

	a := make([]int, n) // Create a slice for the first list
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read elements into the first list
	}

	b := make([]int, n) // Create a slice for the second list
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i]) // Read elements into the second list
	}

	c := make([]int, n) // Create a slice for the third list
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i]) // Read elements into the third list
	}

	x, y, z := 0, 0, 0 // Initialize the sums of the lists

	// Calculate the sum of elements in each list
	for _, value := range a {
		x += value // Add each element of list a to x
	}
	for _, value := range b {
		y += value // Add each element of list b to y
	}
	for _, value := range c {
		z += value // Add each element of list c to z
	}

	// Print the absolute differences between the sums of the lists
	fmt.Println(int(math.Abs(float64(x - y)))) // Print the absolute difference between the sums of lists a and b
	fmt.Println(int(math.Abs(float64(y - z)))) // Print the absolute difference between the sums of lists b and c
}

// <END-OF-CODE>
