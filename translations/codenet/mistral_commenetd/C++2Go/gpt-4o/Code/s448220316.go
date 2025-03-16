package main

import (
	"fmt"
)

var (
	n, m, l, r, vi int
	fa             [100005]int
	v              [200005]int
)

// Read an integer from standard input
func read() int {
	var k, f int = 0, 1
	var ch byte
	for {
		ch = getchar()
		if ch >= '0' && ch <= '9' {
			break
		}
		if ch == '-' {
			f = -1
		}
	}
	for {
		if ch < '0' || ch > '9' {
			break
		}
		k = k*10 + int(ch-'0')
		ch = getchar()
	}
	return k * f
}

// Write an integer to standard output
func write(x int) {
	if x < 0 {
		x = -x
		fmt.Print("-")
	}
	if x > 9 {
		write(x / 10)
	}
	fmt.Print(x % 10)
}

// Write an integer and a newline to standard output
func writeln(x int) {
	write(x)
	fmt.Println()
}

// Get the root of a tree
func get(x int) int {
	if fa[x] == x {
		return x
	}
	f := get(fa[x])
	v[x] += v[fa[x]]
	fa[x] = f
	return f
}

// getchar function to read a byte from standard input
func getchar() byte {
	var b [1]byte
	_, _ = fmt.Scan(b[:])
	return b[0]
}

func main() {
	// Read the number of vertices 'n' and edges 'm'
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
		if li != ri {
			v[ri] += vi - v[r] + v[l] // Update the depth of the right tree
			fa[ri] = li               // Set the father of the right tree to the father of the left tree
		} else {
			// If the roots are the same, check if the value of the edge is correct
			if v[r]-v[l] != vi {
				fmt.Println("No") // Output 'No' if the value is incorrect
				return             // Terminate the program
			}
		}
	}
	// Output 'Yes' if all edges have the correct value
	fmt.Println("Yes")
}

// <END-OF-CODE>
