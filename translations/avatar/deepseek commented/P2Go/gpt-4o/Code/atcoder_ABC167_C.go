package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	// Read the cost matrix
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Scan(&c[i][j])
		}
	}

	// Initialize a slice to store combinations
	var l [][]int
	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}

	// Generate all possible combinations of books
	for i := 1; i <= n; i++ {
		combinations := combinations(pre, i)
		l = append(l, combinations...)
	}

	// Initialize the answer variable to store the minimum cost
	ans := math.MaxInt32

	// Check each combination to see if the total skill level meets the requirement
	for i := 1; i <= m; i++ {
		var rem []int
		for j, k := range l {
			ca := 0
			for _, ii := range k {
				ca += c[ii][i]
			}
			if ca < x {
				rem = append(rem, j)
			}
		}
		if len(rem) > 0 {
			for _, j := range rem {
				l = append(l[:j], l[j+1:]...) // Remove the j-th combination
			}
		}
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}

	// Find the minimum cost among the valid combinations
	for _, i := range l {
		ca := 0
		for _, j := range i {
			ca += c[j][0]
		}
		if ca < ans {
			ans = ca
		}
	}
	fmt.Println(ans)
}

// Helper function to generate combinations
func combinations(arr []int, r int) [][]int {
	var result [][]int
	var comb []int
	var backtrack func(start int, depth int)
	backtrack = func(start int, depth int) {
		if depth == r {
			combCopy := make([]int, r)
			copy(combCopy, comb)
			result = append(result, combCopy)
			return
		}
		for i := start; i < len(arr); i++ {
			comb = append(comb, arr[i])
			backtrack(i+1, depth+1)
			comb = comb[:len(comb)-1]
		}
	}
	backtrack(0, 0)
	return result
}
