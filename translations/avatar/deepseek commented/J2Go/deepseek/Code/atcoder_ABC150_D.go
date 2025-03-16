package main

import (
	"fmt"
	"math"
)

// Helper function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i] /= 2
	}

	lcd := 1

	// Calculate the least common multiple (LCM) of the elements in array a
	for i := 0; i < n; i++ {
		g := gcd(lcd, a[i])
		lcd = lcd * a[i] / g
		if lcd > m {
			fmt.Println(0)
			return
		}
	}

	// Check if the LCM is even for any element in the array
	for i := 0; i < n; i++ {
		if (lcd / a[i]) % 2 == 0 {
			fmt.Println(0)
			return
		}
	}

	// Calculate and print the number of integers up to m that are divisible by the LCM
	fmt.Println((m/lcd+1) / 2)
}

