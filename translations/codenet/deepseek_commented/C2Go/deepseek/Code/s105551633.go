package main

import (
	"fmt"
	"math"
)

// Define a type alias for int64
type int64 = int64

// Define macros for maximum, minimum, and absolute value
func MAX(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func MIN(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func ABS(a int) int {
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
	for i := 1; int64(i)*int64(i) <= n; i++ {
		if n%int64(i) != 0 {
			continue
		}
		a := int64(i)
		b := n / int64(i)
		min = MIN(min, MAX(digit(a), digit(b)))
	}
	fmt.Println(min)
}

// Main function
func main() {
	run()
}

