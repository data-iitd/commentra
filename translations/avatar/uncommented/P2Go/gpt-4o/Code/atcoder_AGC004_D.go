package main

import (
	"fmt"
	"os"
)

var (
	n, k int
	links [][]int
)

func dfs(v, p int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0

	for _, u := range links[v] {
		if u == 0 {
			continue
		}
		hgt, cut := dfs(u, v)
		if hgt > heightFromLeaf {
			heightFromLeaf = hgt
		}
		cutCount += cut
	}
	heightFromLeaf++

	if p != 0 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount++
	}
	return heightFromLeaf, cutCount
}

func main() {
	fmt.Fscan(os.Stdin, &n, &k)
	links = make([][]int, n)

	aaa := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(os.Stdin, &aaa[i])
		aaa[i]-- // Convert to 0-based index
		links[aaa[i]] = append(links[aaa[i]], i+1) // i+1 because we want to connect to the child
	}

	_, ans := dfs(0, 0)
	if aaa[0] != 1 {
		ans++
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
