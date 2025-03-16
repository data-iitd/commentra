
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read an integer from input
func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := fmt.Sscanf(scanner.Text(), "%d")
	return num
}

// Function to write an integer to output
func writeInt(num int) {
	fmt.Println(num)
}

// Global variables for number of nodes, edges, and other parameters
var (
	n, m, l, r, vi, fa, v int
)

// Function to find the representative of a set and update the value
func get(x int) int {
	if x == fa[x] {
		return x
	}
	f := get(fa[x])
	v[x] += v[fa[x]]
	fa[x] = f
	return f
}

func main() {
	n = readInt() // Read number of nodes
	m = readInt() // Read number of edges
	// Initialize the parent array for union-find
	fa = make([]int, n+1)
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	// Process each edge
	for i := 1; i <= m; i++ {
		l = readInt() // Read left node
		r = readInt() // Read right node
		vi = readInt() // Read value to be assigned
		li := get(l) // Find representative of left node
		ri := get(r) // Find representative of right node
		// If they belong to different sets, union them
		if li!= ri {
			v[ri] = vi - v[r] + v[l] // Update the value for the new root
			fa[ri] = li // Union the sets
		} else {
			// If they are in the same set, check for consistency
			if v[r]-v[l]!= vi {
				writeInt(0) // Inconsistent values
				return
			}
		}
	}
	writeInt(1) // All edges processed successfully
}

