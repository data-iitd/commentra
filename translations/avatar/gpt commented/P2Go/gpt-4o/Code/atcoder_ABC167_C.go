package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&c[i][j])
		}
	}

	// Create a slice to hold combinations
	var l [][]int
	// Generate all possible combinations of items of varying lengths
	for i := 1; i <= n; i++ {
		combinations := combinations(pre(n), i)
		l = append(l, combinations...)
	}

	// Initialize the answer variable to store the minimum cost
	ans := math.MaxInt32

	// Iterate over each category from 0 to m-1
	for i := 0; i < m; i++ {
		rem := []int{}
		// Check each combination of items
		for j, k := range l {
			ca := 0 // Initialize cumulative cost for the current combination
			// Calculate the total cost for the current combination in the current category
			for _, ii := range k {
				ca += c[ii][i]
			}

			// If the total cost is less than the threshold x, mark this combination for removal
			if ca < x {
				rem = append(rem, j)
			}
		}

		// Remove combinations that did not meet the cost requirement
		if len(rem) > 0 {
			for j := len(rem) - 1; j >= 0; j-- {
				l = append(l[:rem[j]], l[rem[j]+1:]...)
			}
		}

		// If no valid combinations remain, print -1 and exit
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}

	// If valid combinations remain, calculate the minimum cost for the first category
	for _, i := range l {
		ca := 0 // Initialize cumulative cost for the current combination
		// Calculate the total cost for the current combination in the first category
		for _, j := range i {
			ca += c[j][0]
		}

		// Update the answer with the minimum cost found
		if ca < ans {
			ans = ca
		}
	}

	// Print the minimum cost found
	fmt.Println(ans)
}

// Function to generate combinations of indices
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

// Function to create an array of indices
func pre(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = i
	}
	return arr
}
