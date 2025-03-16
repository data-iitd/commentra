package main

import (
	"fmt"
)

func main() {
	var n, m int
	// Read the first integer n, which represents the number of elements
	fmt.Scan(&n)
	// Read the second integer m, which represents the upper limit
	fmt.Scan(&m)

	// Initialize a slice to hold the processed values
	a := make([]int, n)

	// Read n integers from input, divide each by 2, and store in slice a
	for i := 0; i < n; i++ {
		var input int
		fmt.Scan(&input)
		a[i] = input / 2
	}

	var gcd int64
	lcd := int64(1) // Initialize the least common denominator (lcd) to 1

	// Calculate the least common multiple (lcd) of the slice elements
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, int64(a[i])) // Get the greatest common divisor (gcd) of lcd and current element
		lcd = lcd * int64(a[i]) / gcd  // Update lcd using the formula: lcd = (lcd * a[i]) / gcd

		// If lcd exceeds m, print 0 and exit
		if lcd > int64(m) {
			fmt.Println(0)
			return
		}
	}

	// Check if the condition for each element in the slice is satisfied
	for i := 0; i < n; i++ {
		// If lcd divided by the current element is even, print 0 and exit
		if (lcd/int64(a[i]))%2 == 0 {
			fmt.Println(0)
			return
		}
	}

	// Calculate and print the final result based on the value of m and lcd
	fmt.Println((m/int(lcd)+1)/2)
}

// Function to compute the greatest common divisor (gcd) using recursion
func getGCD(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return getGCD(b, a%b) // Recursive call to find gcd
}

// <END-OF-CODE>
