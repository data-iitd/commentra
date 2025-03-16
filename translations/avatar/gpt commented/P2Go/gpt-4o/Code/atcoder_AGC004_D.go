package main

import (
	"fmt"
	"os"
)

var links [][]int

func dfs(v, p, k int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0

	for _, u := range links[v] {
		if u == 0 {
			continue
		}

		hgt, cut := dfs(u, v, k)
		heightFromLeaf = max(heightFromLeaf, hgt)
		cutCount += cut
	}

	heightFromLeaf++

	if p != 0 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount++
	}

	return heightFromLeaf, cutCount
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k int
	fmt.Fscanf(os.Stdin, "%d %d", &n, &k)

	links = make([][]int, n)
	aaa := make([]int, n-1)

	for i := 0; i < n-1; i++ {
		fmt.Fscanf(os.Stdin, "%d", &aaa[i])
		aaa[i]-- // Adjust for 0-based indexing
		links[aaa[i]] = append(links[aaa[i]], i+1) // i+1 to connect to the child node
	}

	_, ans := dfs(0, 0, k)

	if aaa[0] != 1 {
		ans++
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
