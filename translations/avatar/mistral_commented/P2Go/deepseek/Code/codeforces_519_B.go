package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	var a, b, c []int
	var x, y, z int

	// Read the first list 'a' of numbers from the standard input
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		a = append(a, num)
	}

	// Read the second list 'b' of numbers from the standard input
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		b = append(b, num)
	}

	// Read the third list 'c' of numbers from the standard input
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		c = append(c, num)
	}

	// Initialize variables x, y, and z to 0
	x = 0
	y = 0
	z = 0

	// Iterate through each number in list 'a' and add it to the variable 'x'
	for _, i := range a {
		x += i
	}

	// Iterate through each number in list 'b' and add it to the variable 'y'
	for _, i := range b {
		y += i
	}

	// Iterate through each number in list 'c' and add it to the variable 'z'
	for _, i := range c {
		z += i
	}

	// Print the absolute difference between 'x' and 'y'
	fmt.Println(math.Abs(float64(x - y)))

	// Print the absolute difference between 'y' and 'z'
	fmt.Println(math.Abs(float64(y - z)))
}

