package main

import (
	"fmt"
)

// Include headers for input/output operations.

func read() int {
	var k, f int
	ch := ' '
	// Initialize variables to read integers efficiently.
	for ch < '0' || ch > '9' {
		if ch == '-' {
			f = -1
		}
		ch = readByte()
		// Skip non-digit characters and handle negative numbers.
	}
	for ch >= '0' && ch <= '9' {
		k = k*10 + int(ch-'0')
		ch = readByte()
		// Convert characters to digits and accumulate the result.
	}
	return k * f
	// Return the integer value, considering its sign.
}

// Read function to efficiently read integers.

func write(x int) {
	if x < 0 {
		x = -x
		writeByte('-')
	}
	// Handle negative numbers by converting them to positive.
	if x > 9 {
		write(x / 10)
	}
	// Recursively write the digits of the number.
	writeByte(byte(x%10) + '0')
	// Write the last digit.
}

// Write function to efficiently write integers.

func writeln(x int) {
	write(x)
	writeByte('\n')
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
	n = read()
	m = read()
	// Read the number of nodes and operations.
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	// Initialize the union-find structure with each node as its own parent.
	for i := 1; i <= m; i++ {
		l = read()
		r = read()
		vi = read()
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
				fmt.Println("No")
				return
				// If the values are inconsistent, print "No" and exit.
			}
		}
	}
	fmt.Println("Yes")
	// If all operations are consistent, print "Yes".
}

// Main function to execute the union-find structure and value updates.


