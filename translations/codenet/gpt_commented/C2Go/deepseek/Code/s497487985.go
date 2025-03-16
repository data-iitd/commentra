package main

import (
	"fmt"
)

// Function to calculate the greatest common divisor (GCD) using recursion
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a % b)
	}
}

// Function to calculate the least common multiple (LCM) using GCD
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var n int
	var k int64
	var q int
	var a [100001]int
	var point [100001]int64

	// Read input values for n, k, and q
	fmt.Scan(&n, &k, &q)

	// Process each question and update points for the corresponding participant
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i])
		point[a[i]-1]++
	}

	// Determine if each participant has enough points to win
	for i := 0; i < n; i++ {
		if k-(int64(q)-int64(point[i])) > 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

