package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Reading the first two integers n and m

	a := make([]int, n) // Creating a slice a of size n

	// Initializing the slice a with input values
	for i := 0; i < n; i++ {
		var input int
		fmt.Scan(&input) // Reading an integer value
		a[i] = input / 2 // Dividing it by 2 before storing it in the slice
	}

	var gcd int64 // Declaring a variable gcd to store the greatest common divisor
	lcd := int64(1) // Declaring and initializing a variable lcm to store the least common multiple

	// Finding the least common multiple of all slice elements
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, int64(a[i])) // Finding the greatest common divisor of lcm and the current slice element
		lcd = lcd * int64(a[i]) / gcd // Updating the value of lcm

		// Checking if lcm is greater than m
		if lcd > int64(m) {
			fmt.Println(0) // If true, printing 0 and returning from the method
			return
		}
	}

	// Checking if any slice element is a factor of lcm
	for i := 0; i < n; i++ {
		if (lcd/int64(a[i]))%2 == 0 { // Checking if the remainder of lcm divided by the current slice element is 0 and even
			fmt.Println(0) // If true, printing 0 and returning from the method
			return
		}
	}

	// Printing the result
	fmt.Println((m/int(lcd)+1)/2)
}

// A helper function to find the greatest common divisor of two numbers
func getGCD(a, b int64) int64 {
	if b == 0 { // Base case: if b is 0, return a as the gcd
		return a
	}
	return getGCD(b, a%b) // Recursive call: finding the gcd of b and the remainder of a divided by b
}
