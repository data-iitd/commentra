package main

import (
	"fmt"
	"math"
)

// Define a type alias for int64
type int64 int64

// Define macros for maximum, minimum, and absolute value
func MAX(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func MIN(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func ABS(a int64) int64 {
	if a > 0 {
		return a
	}
	return -a
}

// Function to count the number of digits in a number
func digit(n int64) int {
	res := 0
	for n > 0 {
		res++
		n /= 10
	}
	return res
}

// Main logic of the program
func run() {
	var n int64
	fmt.Scan(&n)
	min := digit(n)
	for i := int64(1); i*i <= n; i++ {
		if n%i != 0 {
			continue
		}
		a := i
		b := n / i
		min = MIN(min, MAX(digit(a), digit(b)))
	}
	fmt.Println(min)
}

// Main function
func main() {
	run()
}

