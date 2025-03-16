package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Read input values for n (number of items), m (number of categories), and x (threshold value)
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	// Read the cost matrix where each row corresponds to an item and each column to a category
	c := make([][]int, n)
	for i := range c {
		c[i] = make([]int, m)
		for j := range c[i] {
			fmt.Scan(&c[i][j])
		}
	}

	// Create an array of indices for the items
	pre := make([]int, n)
	for i := range pre {
		pre[i] = i
	}

	// Initialize lists to hold combinations and to track remaining combinations
	l := make([][]int, 0)
	rem := make([]int, 0)

	// Initialize the answer variable to store the minimum cost
	ans := 0

	// Generate all possible combinations of items of varying lengths
	for i := 0; i < len(pre)+1; i++ {
		for j := range pre {
			l = append(l, pre[j:j+i])
		}
	}

	// Iterate over each category from 1 to m
	for i := 1; i < m+1; i++ {
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
			} else {
				continue
			}
		}

		// Remove combinations that did not meet the cost requirement
		if len(rem) > 0 {
			for j := len(rem) - 1; j >= 0; j-- {
				l = append(l[:rem[j]], l[rem[j]+1:]...)
			}
			rem = rem[:0] // Reset the remaining combinations list
		}

		// If no valid combinations remain, print -1 and exit
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}

	// If valid combinations remain, calculate the minimum cost for the first category
	for _, k := range l {
		ca := 0 // Initialize cumulative cost for the current combination
		// Calculate the total cost for the current combination in the first category
		for _, ii := range k {
			ca += c[ii][0]
		}

		// Update the answer with the minimum cost found
		if ans == 0 {
			ans = ca
		} else {
			ans = int(math.Min(float64(ans), float64(ca)))
		}
	}

	// Print the minimum cost found
	fmt.Println(ans)
}

