

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Inline function to read an integer from standard input
func read() (k int) {
	var f int = 1
	for {
		b := bufio.NewReader(os.Stdin)
		a, _ := b.ReadByte()
		if a == '-' {
			f = -1
		} else if a >= '0' && a <= '9' {
			k = k*10 + int(a) - '0'
		} else {
			break
		}
	}
	return k * f
}

// Inline function to write an integer to standard output
func write(x int) {
	if x < 0 {
		x = -x
		putchar('-')
	}
	if x > 9 {
		write(x / 10)
	}
	putchar(x % 10 + '0')
}

// Inline function to write an integer and a newline to standard output
func writeln(x int) {
	write(x)
	puts("")
}

// Initialize variables
var (
	n, m, l, r, vi, fa, v int
)

// Inline function to get the root of a tree
func get(x int) int {
	if fa[x] == x {
		return x
	}
	// Recursively find the root of the tree
	f := get(fa[x])
	// Update the depth of the nodes on the path from 'x' to the root
	v[x] += v[fa[x]]
	// Update the father of 'x'
	fa[x] = f
	return f
}

// Main function
func main() {
	// Read the number of vertices 'n' and edges'm'
	n = read()
	m = read()
	// Initialize the trees for each vertex
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	// Process each edge
	for i := 1; i <= m; i++ {
		// Read the left and right endpoints and the value 'vi' of the edge
		l = read()
		r = read()
		vi = read()
		// Find the roots of the trees of the left and right endpoints
		li := get(l)
		ri := get(r)
		// If the roots are different, update the depth of the right tree and its father
		if li!= ri {
			v[ri] += vi - v[r] + v[l] // Update the depth of the right tree
			fa[ri] = li // Set the father of the right tree to the father of the left tree
		} else {
			// If the roots are the same, check if the value of the edge is correct
			if v[r]-v[l]!= vi {
				fmt.Println("No") // Output 'No' if the value is incorrect
				return // Terminate the program
			}
		}
	}
	// Output 'Yes' if all edges have the correct value
	fmt.Println("Yes")
}

