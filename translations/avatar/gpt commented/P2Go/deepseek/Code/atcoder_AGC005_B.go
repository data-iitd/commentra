package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a function to find the root of an element using path compression
func root(par []int, x int) int {
	if par[x] == x {
		return x
	}
	return root(par, par[x])
}

// Define a function to check if two elements belong to the same set
func same(par []int, x, y int) bool {
	return root(par, x) == root(par, y)
}

// Define a function to unite two sets containing elements z
func unite(par []int, rank []int, size []int, x, y int) {
	// Find the roots of the elements x and y
	rx := root(par, x)
	ry := root(par, y)
	
	// If the roots are different, unite the sets
	if rx != ry {
		// Union by rank: attach the smaller tree under the larger tree
		if rank[rx] < rank[ry] {
			par[rx] = ry  // Make ry the parent of rx
			size[ry] += size[rx]  // Update the size of the new root
		} else {
			par[ry] = rx  // Make rx the parent of ry
			size[rx] += size[ry]  // Update the size of the new root
			
			// If ranks are equal, increment the rank of the new root
			if rank[rx] == rank[ry] {
				rank[rx]++
			}
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	// Read input values: first value is n, followed by n integers
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}
	
	// Initialize the parent array where each element is its own parent
	par := make([]int, n)
	for i := 0; i < n; i++ {
		par[i] = i
	}
	
	// Initialize rank and size arrays for union-find structure
	rank := make([]int, n)
	size := make([]int, n)
	for i := 0; i < n; i++ {
		rank[i] = 1
		size[i] = 1
	}
	
	// Create an array to store the indices of elements in a
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[a[i]-1] = i  // Store the index of each element in b
	}
	
	// Initialize a counter for the final result
	c := 0
	
	// Iterate through the array b in reverse order
	for i := n - 1; i >= 0; i-- {
		k := b[i]
		l := 1  // Initialize left size
		r := 1  // Initialize right size
		
		// Check if the left neighbor exists and is greater
		if k > 0 && a[k-1] > a[k] {
			l += size[root(par, k-1)]  // Add the size of the left component
			unite(par, rank, size, k-1, k)  // Unite the left neighbor with the current element
		}
		
		// Check if the right neighbor exists and is greater
		if k+1 < n && a[k+1] > a[k] {
			r += size[root(par, k+1)]  // Add the size of the right component
			unite(par, rank, size, k+1, k)  // Unite the right neighbor with the current element
		}
		
		// Update the counter with the product of left size, right size, and the current element's value
		c += l * r * a[k]
	}
	
	// Print the final result
	fmt.Println(c)
}

