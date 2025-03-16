package main

import (
	"fmt"
)

func check(n int, wei int, book []int) bool {
	tmp := wei // Temporary variable to hold the remaining weight
	n--        // Decrease the number of available books by one
	for i := 0; i < len(book); i++ {
		// If the current weight exceeds the available weight
		if tmp < book[i] {
			// If there are still books left to use
			if n > 0 {
				n--          // Use one book
				tmp = wei    // Reset the temporary weight to the original weight
				// Check again if the current weight exceeds the available weight
				if tmp < book[i] {
					return false // Not possible to distribute
				}
			} else {
				return false // No books left to use
			}
		}
		// Deduct the current book's weight from the temporary weight
		tmp -= book[i]
	}
	return true // Successfully distributed the weights
}

func main() {
	var m, n int // m: maximum weight, n: number of books
	// Read input until m is zero
	for {
		fmt.Scan(&m)
		if m == 0 {
			break
		}
		fmt.Scan(&n)
		book := make([]int, n) // Slice to store the weights of the books
		// Read the weights of the books
		for i := 0; i < n; i++ {
			fmt.Scan(&book[i]) // Read each book's weight
		}

		l, r := 0, 1500000 // Lower and upper bounds for binary search
		var ans int        // Variable to store the answer
		// Perform binary search to find the maximum weight that can be distributed
		for l < r {
			mid := (l + r) / 2
			// Check if the middle weight can be distributed
			if check(n, mid, book) {
				ans = mid // Update answer
				r = mid   // Move the upper bound down
			} else {
				l = mid + 1 // Move the lower bound up
			}
		}
		fmt.Println(ans) // Output the maximum weight that can be distributed
	}
}

// <END-OF-CODE>
