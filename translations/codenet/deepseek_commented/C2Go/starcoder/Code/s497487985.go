<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"sort"
)

// Define macros for maximum and minimum values
const (
	MAX = 100001
)

// Function to compare integers in descending order
func compare_int(a, b int) int {
	return b - a
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
<<<<<<< HEAD
	var n, k, q int
	var a [MAX]int
	var point [MAX]int
=======
	var (
		n, k, q int
		a       [MAX]int
		point   [MAX]int
	)
>>>>>>> 98c87cb78a (data updated)

	// Read input values
	fmt.Scanf("%d%d%d", &n, &k, &q)

	// Process each query to update points
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &a[i])
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

