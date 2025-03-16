package main

import (
	"fmt"
	"math"
	"sort"
)

// Define macros for maximum and minimum values
const (
	MAX = math.MaxInt64
	MIN = math.MinInt64
)

// Function to compare integers in descending order
func compare_int(a, b int) int {
	return b - a // 大きい順
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

// Function to calculate the least common multiple (LCM)
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Main function
func main() {
	var n int // Number of players
	var k int64 // Initial points
	var q int // Number of queries
	var a [100001]int // Array to store query results
	var point [100001]int64 // Array to store points for each player

	// Read input values
	fmt.Scan(&n, &k, &q)

	// Process each query to update points
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i])
		point[a[i]-1]++ // Update points for the player who answered the query
	}

	// Determine if each player can reach the required points
	for i := 0; i < n; i++ {
		if k-(q-point[i]) > 0 {
			fmt.Println("Yes") // Player can reach the required points
		} else {
			fmt.Println("No") // Player cannot reach the required points
		}
	}
}

