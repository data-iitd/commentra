package main

import (
	"fmt"
)

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func main() {
	var n int64 // Number of people
	var k int64 // Total points
	var q int64 // Number of queries
	var a [100001]int64 // Array to store the query numbers
	var point [100001]int64 // Array to store the current points for each person

	// Read input values
	fmt.Scan(&n, &k, &q)

	// Check if it's possible to distribute the points to all queries
	if q < k {
		// If the total number of queries is less than the total points, then it's impossible to distribute the points to all queries
		for i := int64(0); i < n; i++ {
			fmt.Println("Yes") // This will never be reached
			return
		}
	}

	// Distribute the points to each query one by one
	for i := int64(0); i < q; i++ {
		fmt.Scan(&a[i]) // Read the query number
		point[a[i]-1]++ // Increase the points for the person with the query number
	}

	// Check if it's possible to distribute the remaining points to the remaining people
	for i := int64(0); i < n; i++ {
		if k-(q-point[i]) > 0 { // If the remaining points are greater than the difference between the total points and the points already distributed
			fmt.Println("Yes") // It's possible to distribute the remaining points to the remaining people
		} else {
			fmt.Println("No") // It's impossible to distribute the remaining points to the remaining people
		}
	}
}

// <END-OF-CODE>
