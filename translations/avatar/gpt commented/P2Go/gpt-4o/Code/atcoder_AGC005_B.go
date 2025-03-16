package main

import (
	"fmt"
)

var par, rank, size []int

// root function to find the root of an element using path compression
func root(x int) int {
	if par[x] == x {
		return x
	}
	par[x] = root(par[x]) // Path compression
	return par[x]
}

// same function to check if two elements belong to the same set
func same(x, y int) bool {
	return root(x) == root(y)
}

// unite function to unite two sets containing elements z
func unite(z ...int) {
	x, y := root(z[0]), root(z[1])
	if x != y {
		// Union by rank: attach the smaller tree under the larger tree
		if rank[x] < rank[y] {
			par[x] = y
			size[y] += size[x]
		} else {
			par[y] = x
			size[x] += size[y]
			if rank[x] == rank[y] {
				rank[x]++
			}
		}
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the parent array where each element is its own parent
	par = make([]int, n)
	for i := range par {
		par[i] = i
	}

	// Initialize rank and size arrays for union-find structure
	rank = make([]int, n)
	size = make([]int, n)
	for i := range rank {
		rank[i] = 1 // All elements start with rank 1
		size[i] = 1 // All elements start with size 1
	}

	// Create an array to store the indices of elements in a
	b := make([]int, n)
	for i, t := range a {
		b[t-1] = i // Store the index of each element in b
	}

	// Initialize a counter for the final result
	c := 0

	// Iterate through the array b in reverse order
	for k := n - 1; k >= 0; k-- {
		l, r := 1, 1 // Initialize left and right sizes

		// Check if the left neighbor exists and is greater
		if k > 0 && a[k-1] > a[k] {
			l += size[root(k-1)] // Add the size of the left component
			unite(k-1, k)        // Unite the left neighbor with the current element
		}

		// Check if the right neighbor exists and is greater
		if k+1 < n && a[k+1] > a[k] {
			r += size[root(k+1)] // Add the size of the right component
			unite(k+1, k)        // Unite the right neighbor with the current element
		}

		// Update the counter with the product of left size, right size, and the current element's value
		c += l * r * a[k]
	}

	// Print the final result
	fmt.Println(c)
}

// <END-OF-CODE>
