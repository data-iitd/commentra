// Import necessary libraries
package main

import (
	"fmt"
	"math"
	"sort"
)

// Take input dimensions and threshold from user
func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	// Initialize numpy array 'c' with dimensions (n, m)
	c := make([][]int, n)
	for i := range c {
		c[i] = make([]int, m)
		for j := range c[i] {
			fmt.Scan(&c[i][j])
		}
	}

	// Initialize empty lists 'l' for storing combinations and 'rem' for storing indices
	l := make([][]int, 0)
	rem := make([]int, 0)

	// Initialize variable 'ans' for storing minimum number of tests
	ans := 0

	// Loop through all possible combinations of 'pre' indices
	for i := 0; i <= len(pre); i++ {
		// Generate all combinations of 'pre' indices of size 'i'
		for j := 0; j < int(math.Pow(2, float64(i))); j++ {
			// Append the combination to list 'l'
			l = append(l, make([]int, i))
			for k := 0; k < i; k++ {
				if j&(1<<k) != 0 {
					l[len(l)-1][k] = pre[k]
				}
			}
		}
	}

	// Loop through each iteration 'i' of test cases
	for i := 1; i <= m; i++ {
		// Initialize variable 'ca' to 0 for sum of tests in current combination
		ca := 0

		// Loop through each index 'j' in current combination
		for j := 0; j < len(l[i]); j++ {
			// Add the test result at index 'j' and test case 'i' to 'ca'
			ca += c[l[i][j]][i]
		}

		// If the sum of tests in current combination is less than threshold 'x',
		// add the index of the current combination to 'rem' list
		if ca < x {
			rem = append(rem, i)
		}
		// If the sum of tests in current combination is greater than or equal to threshold 'x',
		// continue to next combination
		else {
			continue
		}

		// If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
		if len(rem) > 0 {
			for j := 0; j < len(rem); j++ {
				l = append(l[:rem[j]], l[rem[j]+1:]...)
			}
			rem = rem[:0]
		}

		// If 'l' list is empty, print -1 and break the loop
		if len(l) == 0 {
			fmt.Println(-1)
			break
		}
	}

	// If the loop completes without finding a valid combination,
	// calculate the minimum number of tests in all valid combinations
	if len(l) > 0 {
		// Initialize variable 'ca' to 0 for sum of tests in current combination
		ca := 0

		// Loop through each valid combination and calculate the sum of tests
		for i := 0; i < len(l); i++ {
			ca = 0
			for j := 0; j < len(l[i]); j++ {
				ca += c[l[i][j]][0]
			}

			// Update 'ans' with minimum number of tests among all valid combinations
			if ans == 0 {
				ans = ca
			} else {
				ans = int(math.Min(float64(ans), float64(ca)))
			}
		}

		// Print the minimum number of tests required
		fmt.Println(ans)
	}
}

