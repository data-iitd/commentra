package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	// Calculate the maximum value based on the formula and print it
	// The formula computes x + y - 3 and adjusts based on the difference between y and x
	// It ensures the result is not negative by taking the maximum with 0
	result := int(math.Max(float64(x+y-3+((y-x)%3 > 0)), 0))
	fmt.Println(result)
}

// Define a function to read a single integer from input
func numInp() int {
	var input int
	fmt.Scan(&input)
	return input
}

// Define a function to read a list of integers from input
func arrInp() []int {
	var input []int
	var num int
	fmt.Scan(&num)
	for i := 0; i < num; i++ {
		var val int
		fmt.Scan(&val)
		input = append(input, val)
	}
	return input
}

// Define a function to read a space-separated list of integers from input
func spInp() []int {
	var input []int
	var num int
	fmt.Scan(&num)
	for i := 0; i < num; i++ {
		var val int
		fmt.Scan(&val)
		input = append(input, val)
	}
	return input
}

// Define a function to read a string from input
func strInp() string {
	var input string
	fmt.Scan(&input)
	return input
}
