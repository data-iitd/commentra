package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values for n (number of items), m (number of categories), and x (threshold value)
	n, m, x := readInput()

	// Read the cost matrix where each row corresponds to an item and each column to a category
	c := readCostMatrix(n)

	// Create an array of indices for the items
	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}

	// Initialize lists to hold combinations and to track remaining combinations
	l := make([][]int, 0)
	rem := make([]int, 0)

	// Initialize the answer variable to store the minimum cost
	ans := 0

	// Generate all possible combinations of items of varying lengths
	for i := 1; i <= n; i++ {
		for j := range combinations(pre, i) {
			l = append(l, j)
		}
	}

	// Iterate over each category from 1 to m
	for i := 1; i <= m; i++ {
		// Check each combination of items
		for j, k := range l {
			ca := 0  // Initialize cumulative cost for the current combination
			// Calculate the total cost for the current combination in the current category
			for ii := range k {
				ca += c[k[ii]][i]
			}

			// If the total cost is less than the threshold x, mark this combination for removal
			if ca < x {
				rem = append(rem, j)
			} else {
				continue
			}
		}

		// Remove combinations that did not meet the cost requirement
		if len(rem) > 0 {
			for j := range rem {
				l = append(l[:j], l[j+1:]...)
			}
			rem = make([]int, 0)  // Reset the remaining combinations list
		}

		// If no valid combinations remain, print -1 and exit
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}

		// If valid combinations remain, calculate the minimum cost for the first category
		for i := range l {
			ca := 0  // Initialize cumulative cost for the current combination
			// Calculate the total cost for the current combination in the first category
			for j := range l[i] {
				ca += c[l[i][j]][0]
			}

			// Update the answer with the minimum cost found
			if ans == 0 {
				ans = ca
			} else {
				ans = min(ans, ca)
		}
	}

	// Print the minimum cost found
	fmt.Println(ans)
}

// Read input values for n (number of items), m (number of categories), and x (threshold value)
func readInput() (int, int, int) {
	var n, m, x int
	fmt.Scanf("%d %d %d", &n, &m, &x)
	return n, m, x
}

// Read the cost matrix where each row corresponds to an item and each column to a category
func readCostMatrix(n int) [][]int {
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		var row []int
		for j := 0; j < m; j++ {
			var val int
			fmt.Scanf("%d", &val)
			row = append(row, val)
		}
		c[i] = row
	}
	return c
}

// Generate all possible combinations of items of varying lengths
func combinations(pre []int, i int) [][]int {
	var l [][]int
	for j := range pre {
		if i == 1 {
			l = append(l, []int{pre[j]})
		} else {
			for k := range combinations(pre[j+1:], i-1) {
				l = append(l, append([]int{pre[j]}, k...))
			}
		}
	}
	return l
}

// Return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

