package main

import (
	"fmt"
	"os"
)

var links [][]int

// dfs function performs depth-first search and returns the height from leaf and cut count
func dfs(n, k, v, p int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0

	for _, u := range links[v] {
		if u == 0 {
			continue
		}

		hgt, cut := dfs(n, k, u, v)
		if hgt > heightFromLeaf {
			heightFromLeaf = hgt
		}
		cutCount += cut
	}

	heightFromLeaf++

	if p != -1 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount++
	}

	return heightFromLeaf, cutCount
}

func main() {
	var n, k int
	fmt.Fscan(os.Stdin, &n, &k)

	links = make([][]int, n)
	aaa := make([]int, n-1)

	for i := 0; i < n-1; i++ {
		fmt.Fscan(os.Stdin, &aaa[i])
		aaa[i]-- // Convert to 0-based index
		links[aaa[i]] = append(links[aaa[i]], i+1) // Add edge to the links
	}

	_, ans := dfs(n, k, 0, -1)

	if aaa[0] != 1 {
		ans++
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
