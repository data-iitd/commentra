package main

import (
	"fmt"
	"math"
)

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
	fmt.Scanf("%d", &n)
	min := digit(n)
	for i := int64(1); i*i <= n; i++ {
		if n%i != 0 {
			continue
		}
		a := i
		b := n / i
		min = int(math.Min(float64(min), float64(max(digit(a), digit(b)))))
	}
	fmt.Println(min)
}

// Function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function
func main() {
	run()
}

// <END-OF-CODE>
