package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define the root function which returns the root of a tree node
// This function uses recursion to find the root of a node by traversing up the tree
// until it reaches the root node or a node with the same parent
func root(par []int, x int) int {
	if par[x] == x {
		return x
	}
	return root(par, par[x])
}

// Define the same function which checks if two nodes have the same root
// This function is used to check if two nodes belong to the same tree
func same(par []int, x, y int) bool {
	return root(par, x) == root(par, y)
}

// Define the unite function which merges two trees into one
// This function sets the parent of the smaller tree to the root of the larger tree
// and updates the size of the root node accordingly
func unite(par []int, rank []int, size []int, x, y int) {
	x, y = root(par, x), root(par, y)
	if x != y {
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read input from standard input and initialize variables
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}

	// Initialize parent and rank lists with given size
	par := make([]int, n)
	for i := 0; i < n; i++ {
		par[i] = i
	}
	rank := make([]int, n)
	for i := 0; i < n; i++ {
		rank[i] = 1
	}
	size := make([]int, n)
	for i := 0; i < n; i++ {
		size[i] = 1
	}

	// Initialize a list b to store the indices of elements in the input list a
	b := make([]int, n)

	// Iterate through the input list and store the indices of elements in list b
	for i := 0; i < n; i++ {
		scanner.Scan()
		t := 0
		fmt.Sscan(scanner.Text(), &t)
		b[t-1] = i
	}

	// Initialize a variable c to store the result
	c := 0

	// Iterate through the list b from the second element to the first
	for k := n - 1; k >= 0; k-- {
		// Initialize variables l and r to store the sizes of the left and right subtrees
		l, r := 1, 1

		// Check if the current node k has a larger element to its left
		if b[k] > 0 && a[b[k]-1] > a[b[k]] {
			// If yes, update l with the size of the left subtree
			l += size[root(par, b[k]-1)]
			// Merge the left and current subtrees
			unite(par, rank, size, b[k]-1, b[k])
		}

		// Check if the current node k has a larger element to its right
		if b[k] < n-1 && a[b[k]+1] > a[b[k]] {
			// If yes, update r with the size of the right subtree
			r += size[root(par, b[k]+1)]
			// Merge the right and current subtrees
			unite(par, rank, size, b[k]+1, b[k])
		}

		// Update the result variable c with the product of the sizes of the left and right subtrees
		// and the value of the current element
		c += l * r * a[b[k]]
	}

	// Print the result
	fmt.Println(c)
}

