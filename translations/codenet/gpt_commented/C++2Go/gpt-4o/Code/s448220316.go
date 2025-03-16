package main

import (
	"fmt"
)

var (
	n, m, l, r, vi int
	fa             [100005]int
	v              [200005]int
)

// Function to find the representative of a set and update the value
func get(x int) int {
	if x == fa[x] {
		return x // If x is its own parent, return it
	}
	f := get(fa[x]) // Recursively find the root
	v[x] += v[fa[x]] // Update the value based on the parent
	fa[x] = f       // Path compression
	return f
}

func main() {
	fmt.Scan(&n) // Read number of nodes
	fmt.Scan(&m) // Read number of edges

	// Initialize the parent array for union-find
	for i := 1; i <= n; i++ {
		fa[i] = i
	}

	// Process each edge
	for i := 1; i <= m; i++ {
		fmt.Scan(&l) // Read left node
		fmt.Scan(&r) // Read right node
		fmt.Scan(&vi) // Read value to be assigned
		li := get(l) // Find representative of left node
		ri := get(r) // Find representative of right node

		// If they belong to different sets, union them
		if li != ri {
			v[ri] = vi - v[r] + v[l] // Update the value for the new root
			fa[ri] = li              // Union the sets
		} else {
			// If they are in the same set, check for consistency
			if v[r]-v[l] != vi {
				fmt.Println("No") // Inconsistent values
				return
			}
		}
	}
	fmt.Println("Yes") // All edges processed successfully
}

// <END-OF-CODE>
