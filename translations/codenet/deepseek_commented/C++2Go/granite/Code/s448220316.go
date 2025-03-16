
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Import necessary packages for input/output operations.

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	// Read an integer from standard input.
	return num
}

// Read function to efficiently read integers from standard input.

func writeInt(num int) {
	fmt.Println(num)
	// Write an integer to standard output.
}

// Write function to efficiently write integers to standard output.

func writeln(num int) {
	writeInt(num)
	// Write the integer and then print a newline.
}

// Writeln function to write integers and print a newline.

func get(x int) int {
	if x == fa[x] {
		return x
		// Base case: if x is the root of itself, return x.
	}
	f := get(fa[x])
	// Recursively find the root of x's parent.
	v[x] += v[fa[x]]
	// Update the value of x based on its parent's value.
	return fa[x] = f
	// Set the parent of x to the root and return the root.
}

// Get function to find the root of a node and update the value array.

func main() {
	n := readInt()
	m := readInt()
	// Read the number of nodes and operations.
	for i := 1; i <= n; i++ {
		fa[i] = i
		// Initialize the union-find structure with each node as its own parent.
	}
	for i := 1; i <= m; i++ {
		l := readInt()
		r := readInt()
		vi := readInt()
		// Read the left node, right node, and value increment for each operation.
		li := get(l)
		ri := get(r)
		// Find the roots of l and r.
		if li!= ri {
			v[ri] = vi - v[r] + v[l]
			// Update the value of ri based on the values of l and r.
			fa[ri] = li
			// Set the parent of ri to li.
		} else {
			if v[r]-v[l]!= vi {
				writeln(0)
				// If the values are inconsistent, print "No" and exit.
				return
			}
		}
	}
	writeln(1)
	// If all operations are consistent, print "Yes".
}

// Main function to execute the union-find structure and value updates.

