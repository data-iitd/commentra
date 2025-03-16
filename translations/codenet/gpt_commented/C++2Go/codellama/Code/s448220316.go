package main

import (
	"fmt"
)

// Function to read an integer from input
func read() int {
	var k, f int // Initialize value and sign
	ch := getchar() // Read a character from input
	// Skip non-digit characters and check for negative sign
	for ch < '0' || ch > '9' {
		if ch == '-' {
			f = -1 // Set sign if negative
		}
		ch = getchar() // Read next character
	}
	// Construct the integer from the digits read
	for ch >= '0' && ch <= '9' {
		k = k*10 + ch - '0' // Build the number
		ch = getchar() // Read next character
	}
	return k * f // Return the final integer with sign
}

// Function to write an integer to output
func write(x int) {
	if x < 0 {
		x = -x
		fmt.Printf("-") // Print negative sign if needed
	}
	if x > 9 {
		write(x / 10) // Recursively write the digits
	}
	fmt.Printf("%d", x%10+'0') // Print the last digit
}

// Function to write an integer followed by a newline
func writeln(x int) {
	write(x) // Write the integer
	fmt.Printf("\n") // Print a newline
}

// Global variables for number of nodes, edges, and other parameters
var n, m, l, r, vi, fa [100005]int
var v [200005]int

// Function to find the representative of a set and update the value
func get(x int) int {
	if x == fa[x] {
		return x // If x is its own parent, return it
	}
	f := get(fa[x]) // Recursively find the root
	v[x] += v[fa[x]] // Update the value based on the parent
	return fa[x] = f // Path compression
}

func main() {
	n = read() // Read number of nodes
	m = read() // Read number of edges
	// Initialize the parent array for union-find
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	// Process each edge
	for i := 1; i <= m; i++ {
		l = read() // Read left node
		r = read() // Read right node
		vi = read() // Read value to be assigned
		li := get(l) // Find representatives of both nodes
		ri := get(r)
		// If they belong to different sets, union them
		if li != ri {
			v[ri] = vi - v[r] + v[l] // Update the value for the new root
			fa[ri] = li // Union the sets
		} else {
			// If they are in the same set, check for consistency
			if v[r]-v[l] != vi {
				fmt.Printf("No\n") // Inconsistent values
				return // Exit the program
			}
		}
	}
	fmt.Printf("Yes\n") // All edges processed successfully
}

