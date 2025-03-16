package main

import (
	"bufio"
	"fmt"
	"os"
)

// Include headers for input/output operations.

func readInt() int {
	var k int
	var f int = 1
	var ch byte
	fmt.Scanf("%c", &ch)
	// Initialize variables to read integers efficiently.
	for ch < '0' || ch > '9' {
		if ch == '-' {
			f = -1
		}
		fmt.Scanf("%c", &ch)
	}
	// Skip non-digit characters and handle negative numbers.
	for ch >= '0' && ch <= '9' {
		k = k*10 + int(ch-'0')
		fmt.Scanf("%c", &ch)
	}
	// Convert characters to digits and accumulate the result.
	return k * f
	// Return the integer value, considering its sign.
}

// Read function to efficiently read integers.

func writeInt(x int) {
	if x < 0 {
		x = -x
		fmt.Printf("-")
	}
	// Handle negative numbers by converting them to positive.
	if x > 9 {
		writeInt(x / 10)
	}
	// Recursively write the digits of the number.
	fmt.Printf("%c", byte(x%10+'0'))
	// Write the last digit.
}

// Write function to efficiently write integers.

func writelnInt(x int) {
	writeInt(x)
	fmt.Printf("\n")
	// Write the integer and then print a newline.
}

// Writeln function to write integers and print a newline.

var (
	n, m, l, r, vi int
	fa             [100005]int
	v              [200005]int
)

// Declare global variables for the number of nodes, number of operations, and arrays for union-find structure and values.

func get(x int) int {
	if x == fa[x] {
		return x
	}
	// Base case: if x is the root of itself, return x.
	f := get(fa[x])
	// Recursively find the root of x's parent.
	v[x] += v[fa[x]]
	// Update the value of x based on its parent's value.
	fa[x] = f
	// Set the parent of x to the root and return the root.
	return f
}

// Get function to find the root of a node and update the value array.

func main() {
	n = readInt()
	m = readInt()
	// Read the number of nodes and operations.
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	// Initialize the union-find structure with each node as its own parent.
	for i := 1; i <= m; i++ {
		l = readInt()
		r = readInt()
		vi = readInt()
		// Read the left node, right node, and value increment for each operation.
		li := get(l)
		ri := get(r)
		// Find the roots of l and r.
		if li != ri {
			v[ri] = vi - v[r] + v[l]
			// Update the value of ri based on the values of l and r.
			fa[ri] = li
			// Set the parent of ri to li.
		} else {
			if v[r]-v[l] != vi {
				fmt.Printf("No\n")
				return
				// If the values are inconsistent, print "No" and exit.
			}
		}
	}
	fmt.Printf("Yes\n")
	// If all operations are consistent, print "Yes".
}

// Main function to execute the union-find structure and value updates.

