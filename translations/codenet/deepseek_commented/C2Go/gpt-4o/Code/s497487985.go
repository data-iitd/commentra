package main

import (
	"fmt"
)

func main() {
	var n int64   // Number of players
	var k int64   // Initial points
	var q int64   // Number of queries
	var a [100001]int64 // Array to store query results
	var point [100001]int64 // Array to store points for each player

	// Read input values
	fmt.Scan(&n, &k, &q)

	// Process each query to update points
	for i := int64(0); i < q; i++ {
		var index int64
		fmt.Scan(&index)
		point[index-1]++ // Update points for the player who answered the query
	}

	// Determine if each player can reach the required points
	for i := int64(0); i < n; i++ {
		if k-(q-point[i]) > 0 {
			fmt.Println("Yes") // Player can reach the required points
		} else {
			fmt.Println("No") // Player cannot reach the required points
		}
	}
}

// <END-OF-CODE>
