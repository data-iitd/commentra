package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define the root function to find the root of a given element in a disjoint set
func root(par []int, x int) int {
	if par[x] == x {
		return x
	}
	return root(par, par[x])
}

// Define the same function to check if two elements are in the same set
func same(par []int, x, y int) bool {
	return root(par, x) == root(par, y)
}

// Define the unite function to merge two sets containing the given elements
func unite(par []int, rank []int, size []int, x, y int) {
	x = root(par, x)
	y = root(par, y)
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

	// Read the input, initialize the disjoint set, and process the array
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}

	par := make([]int, n)
	rank := make([]int, n)
	size := make([]int, n)
	for i := 0; i < n; i++ {
		par[i] = i
		rank[i] = 1
		size[i] = 1
	}
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}

	c := 0

	// Process the array in reverse order to calculate the result
	for i := n - 1; i >= 0; i-- {
		k := b[i]
		l := 1
		r := 1
		if k > 0 && a[k-1] > a[k] {
			l += size[root(par, k-1)]
			unite(par, rank, size, k-1, k)
		}
		if k < n-1 && a[k+1] > a[k] {
			r += size[root(par, k+1)]
			unite(par, rank, size, k+1, k)
		}
		c += l * r * a[k]
	}

	// Print the final result
	fmt.Println(c)
}

