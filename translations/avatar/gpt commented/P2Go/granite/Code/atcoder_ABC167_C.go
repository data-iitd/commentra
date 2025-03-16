
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values for n (number of items), m (number of categories), and x (threshold value)
	var n, m, x int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &n, &m, &x)

	// Read the cost matrix where each row corresponds to an item and each column to a category
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &c[i][j])
		}
	}

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
		for _, j := range combinations(pre, i) {
			l = append(l, j)
		}
	}

	// Iterate over each category from 1 to m
	for i := 1; i <= m; i++ {
		// Check each combination of items
		for j, k := range l {
			ca := 0 // Initialize cumulative cost for the current combination
			// Calculate the total cost for the current combination in the current category
			for _, ii := range k {
				ca += c[ii][i-1]
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
			for _, j := range rem {
				l = append(l[:j], l[j+1:]...)
			}
			rem = make([]int, 0) // Reset the remaining combinations list
		}

		// If no valid combinations remain, print -1 and exit
		if len(l) == 0 {
			fmt.Println(-1)
			break
		}
	} else {
		// If valid combinations remain, calculate the minimum cost for the first category
		for _, i := range l {
			ca := 0 // Initialize cumulative cost for the current combination
			// Calculate the total cost for the current combination in the first category
			for _, j := range i {
				ca += c[j][0]
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
}

func combinations(arr []int, r int) [][]int {
	var result [][]int
	var combination []int
	backtrack(&result, &combination, arr, 0, r)
	return result
}

func backtrack(result *[][]int, combination *[]int, arr []int, start int, r int) {
	if len(*combination) == r {
		*result = append(*result, append([]int{}, *combination...))
		return
	}

	for i := start; i < len(arr); i++ {
		*combination = append(*combination, arr[i])
		backtrack(result, combination, arr, i+1, r)
		*combination = (*combination)[:len(*combination)-1]
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

