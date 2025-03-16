package main

import (
	"fmt"
)

// Function to find the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to find the least common multiple (LCM) of two integers
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var n int // Number of people
	var k int64 // Total points
	var q int // Number of queries
	var a [100001]int // Array to store the query numbers
	var point [100001]int64 // Array to store the current points for each person

	// Read input values
	fmt.Scan(&n, &k, &q)

	// Distribute the points to each query one by one
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i])
		point[a[i]-1]++ // Increase the points for the person with the query number
	}

	// Check if it's possible to distribute the remaining points to the remaining people
	for i := 0; i < n; i++ {
		if k-(int64(q)-int64(point[i])) > 0 { // If the remaining points are greater than the difference between the total points and the points already distributed
			fmt.Println("Yes") // It's possible to distribute the remaining points to the remaining people
		} else {
			fmt.Println("No") // It's impossible to distribute the remaining points to the remaining people
		}
	}
}

