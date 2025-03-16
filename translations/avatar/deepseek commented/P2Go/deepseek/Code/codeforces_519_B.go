package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)  // Read the number of elements in each list

	var a, b, c []int
	var x, y, z int

	// Read the first list of integers
	for i := 0; i < n; i++ {
		var val int
		fmt.Scan(&val)
		a = append(a, val)
	}

	// Read the second list of integers
	for i := 0; i < n; i++ {
		var val int
		fmt.Scan(&val)
		b = append(b, val)
	}

	// Read the third list of integers
	for i := 0; i < n; i++ {
		var val int
		fmt.Scan(&val)
		c = append(c, val)
	}

	// Calculate the sum of elements in each list
	for _, i := range a {
		x += i  // Add each element of list a to x
	}
	for _, i := range b {
		y += i  // Add each element of list b to y
	}
	for _, i := range c {
		z += i  // Add each element of list c to z
	}

	// Print the absolute differences between the sums of the lists
	fmt.Println(int(math.Abs(float64(x - y))))  // Print the absolute difference between the sums of lists a and b
	fmt.Println(int(math.Abs(float64(y - z))))  // Print the absolute difference between the sums of lists b and c
}

