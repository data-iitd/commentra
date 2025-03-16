package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read an integer from input
func read() int {
	var k int
	var f int = 1
	var ch byte
	fmt.Scanf("%c", &ch) // Read a character from input
	// Skip non-digit characters and check for negative sign
	for ch < '0' || ch > '9' {
		if ch == '-' {
			f = -1
		}
		fmt.Scanf("%c", &ch) // Read next character
	}
	// Construct the integer from the digits read
	for ch >= '0' && ch <= '9' {
		k = k*10 + int(ch-'0') // Build the number
		fmt.Scanf("%c", &ch) // Read next character
	}
	return k * f
}

// Function to write an integer to output
func write(x int) {
	if x < 0 {
		x = -x
		fmt.Print("-")
	}
	if x > 9 {
		write(x / 10)
	}
	fmt.Print(string(x%10 + '0'))
}

// Function to write an integer followed by a newline
func writeln(x int) {
	write(x)
	fmt.Println()
}

// Global variables for number of nodes, edges, and other parameters
var n, m, l, r, vi int
var fa [100005]int
var v [200005]int

// Function to find the representative of a set and update the value
func get(x int) int {
	if x == fa[x] {
		return x
	}
	f := get(fa[x])
	v[x] += v[fa[x]]
	fa[x] = f
	return fa[x]
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
		li := get(l)
		ri := get(r)
		// If they belong to different sets, union them
		if li != ri {
			v[ri] = vi - v[r] + v[l]
			fa[ri] = li
		} else {
			// If they are in the same set, check for consistency
			if v[r]-v[l] != vi {
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}

