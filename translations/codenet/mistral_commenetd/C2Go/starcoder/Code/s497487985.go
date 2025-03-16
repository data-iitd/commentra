<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

// Function to compare two integers in descending order
func compare_int(a, b int) bool {
	return a > b
}

// Function to find the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

// Function to find the least common multiple (LCM) of two integers
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Main function
func main() {
	var n, k, q int
	var a []int
	var point []int

	// Read input values
	fmt.Scanf("%d %d %d", &n, &k, &q)

	// Check if it's possible to distribute the points to all queries
	if q < k {
		// If the total number of queries is less than the total points, then it's impossible to distribute the points to all queries
		for i := 0; i < n; i++ {
			fmt.Println("Yes") // This will never be reached
			return
		}
	}

	// Initialize the points for all people to 'k'
	point = make([]int, n)
	for i := 0; i < n; i++ {
		point[i] = k
	}

	// Distribute the points to each query one by one
	for i := 0; i < q; i++ {
		var x int
		fmt.Scanf("%d", &x) // Read the query number
		point[x-1]++       // Increase the points for the person with the query number

		// Try to distribute the points to other people if the current person doesn't get the point
		for j := 0; j < n; j++ {
			if a[i]!= (j+1) && point[j] < k { // If the current person's number is different from 'j + 1' and the points for person 'j' are less than 'k'
				point[j]++ // Increase the points for person 'j'
			}
		}
	}

	// Check if it's possible to distribute the remaining points to the remaining people
	for i := 0; i < n; i++ {
		if k-(q-point[i]) > 0 { // If the remaining points are greater than the difference between the total points and the points already distributed
			fmt.Println("Yes") // It's possible to distribute the remaining points to the remaining people
		} else {
			fmt.Println("No") // It's impossible to distribute the remaining points to the remaining people
		}
	}
}

