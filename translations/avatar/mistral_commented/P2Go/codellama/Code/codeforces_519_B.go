package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take the number of test cases as input
	var n int
	fmt.Scan(&n)

	// Read the first list 'a' of numbers from the standard input
	var a []int
	fmt.Scan(&a)

	// Read the second list 'b' of numbers from the standard input
	var b []int
	fmt.Scan(&b)

	// Read the third list 'c' of numbers from the standard input
	var c []int
	fmt.Scan(&c)

	// Initialize variables x, y, and z to 0
	var x, y, z int

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
	fmt.Println(abs(x - y))

	// Print the absolute difference between 'y' and 'z'
	fmt.Println(abs(y - z))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

