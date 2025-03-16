
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Define a function to find the root of an element using path compression
	root := func(x int) int {
		if par[x] == x {
			return x
		}
		par[x] = root(par[x])
		return par[x]
	}

	// Define a function to check if two elements belong to the same set
	same := func(x, y int) bool {
		return root(x) == root(y)
	}

	// Define a function to unite two sets containing elements z
	unite := func(z...int) {
		// Find the roots of the elements z
		x, y := root(z[0]), root(z[1])

		// If the roots are different, unite the sets
		if x!= y {
			// Union by rank: attach the smaller tree under the larger tree
			if rank[x] < rank[y] {
				par[x] = y  // Make y the parent of x
				size[y] += size[x]  // Update the size of the new root
			} else {
				par[y] = x  // Make x the parent of y
				size[x] += size[y]  // Update the size of the new root

				// If ranks are equal, increment the rank of the new root
				if rank[x] == rank[y] {
					rank[x]++
				}
			}
		}
	}

	// Read input values: first value is n, followed by n integers
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = fmt.Sscanf(scanner.Text(), "%d")
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &a[i])
		b[a[i]-1] = i  // Store the index of each element in b
	}

	// Initialize the parent array where each element is its own parent
	par := make([]int, n)
	for i := range par {
		par[i] = i
	}

	// Initialize rank and size arrays for union-find structure
	rank := make([]int, n)
	size := make([]int, n)
	for i := range rank {
		rank[i] = 1  // All elements start with rank 1
		size[i] = 1  // All elements start with size 1
	}

	// Initialize a counter for the final result
	c := 0

	// Iterate through the array b in reverse order
	for k := n - 1; k >= 0; k-- {
		l, r := 1, 1  // Initialize left and right sizes

		// Check if the left neighbor exists and is greater
		if k > 0 && a[k-1] > a[k] {
			l += size[root(k-1)]  // Add the size of the left component
			unite(k-1, k)  // Unite the left neighbor with the current element
		}

		// Check if the right neighbor exists and is greater
		if k+1 < n && a[k+1] > a[k] {
			r += size[root(k+1)]  // Add the size of the right component
			unite(k+1, k)  // Unite the right neighbor with the current element
		}

		// Update the counter with the product of left size, right size, and the current element's value
		c += l * r * a[k]
	}

	// Print the final result
	fmt.Println(c)
}

