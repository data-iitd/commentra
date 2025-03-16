package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n) // Read the first integer n
	fmt.Scan(&m) // Read the second integer m
	a := make([]int, n)

	// Initialize array a with size n, where each element is half of the next input
	for i := 0; i < n; i++ {
		var input int
		fmt.Scan(&input)
		a[i] = input / 2
	}

	var gcd int64
	lcd := int64(1)

	// Calculate the least common multiple (LCM) of the elements in array a
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, int64(a[i]))
		lcd = lcd * int64(a[i]) / gcd
		if lcd > int64(m) { // Check if LCM exceeds m
			fmt.Println(0)
			return
		}
	}

	// Check if the LCM is even for any element in the array
	for i := 0; i < n; i++ {
		if (lcd/int64(a[i]))%2 == 0 {
			fmt.Println(0)
			return
		}
	}

	// Calculate and print the number of integers up to m that are divisible by the LCM
	fmt.Println((m/int(lcd)+1)/2)
}

// Helper function to compute the greatest common divisor (GCD) of two numbers
func getGCD(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return getGCD(b, a%b)
}
