package main

import (
	"fmt"
	"math"
)

// Function to compute the greatest common divisor (gcd) using recursion
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	// Create a Scanner object to read input from the console
	var n, m int
	fmt.Scan(&n, &m)
	
	// Initialize a slice to hold the processed values
	a := make([]int, n)
	
	// Read n integers from input, divide each by 2, and store in slice a
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i] /= 2
	}
	
	lcd := 1
	
	// Calculate the least common multiple (lcd) of the slice elements
	for i := 0; i < n; i++ {
		g := gcd(lcd, a[i])
		lcd = lcd * a[i] / g
		
		// If lcd exceeds m, print 0 and exit
		if lcd > m {
			fmt.Println(0)
			return
		}
	}
	
	// Check if the condition for each element in the slice is satisfied
	for i := 0; i < n; i++ {
		// If lcd divided by the current element is even, print 0 and exit
		if (lcd / a[i]) % 2 == 0 {
			fmt.Println(0)
			return
		}
	}
	
	// Calculate and print the final result based on the value of m and lcd
	fmt.Println((m / lcd + 1) / 2)
}
