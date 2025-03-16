package main

import (
	"fmt"
)

var par []int
var rank []int
var size []int

// root function to find the root of a given element in a disjoint set
func root(x int) int {
	if par[x] == x {
		return x
	}
	par[x] = root(par[x]) // Path compression
	return par[x]
}

// same function to check if two elements are in the same set
func same(x, y int) bool {
	return root(x) == root(y)
}

// unite function to merge two sets containing the given elements
func unite(z ...int) {
	x, y := root(z[0]), root(z[1])
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
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	par = make([]int, n)
	rank = make([]int, n)
	size = make([]int, n)
	b := make([]int, n)

	for i := 0; i < n; i++ {
		par[i] = i
		rank[i] = 1
		size[i] = 1
	}

	for i, t := range a {
		b[t-1] = i
	}

	c := 0

	// Process the array in reverse order to calculate the result
	for k := n - 1; k >= 0; k-- {
		l, r := 1, 1
		if k > 0 && a[k-1] > a[k] {
			l += size[root(k-1)]
			unite(k-1, k)
		}
		if k+1 < n && a[k+1] > a[k] {
			r += size[root(k+1)]
			unite(k+1, k)
		}
		c += l * r * a[k]
	}

	// Print the final result
	fmt.Println(c)
}

// <END-OF-CODE>
