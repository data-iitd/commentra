package main

import (
	"fmt"
	"math"
)

func main() {
	// Take input dimensions and threshold from user
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	// Initialize a 2D slice 'c' with dimensions (n, m)
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&c[i][j])
		}
	}

	// Initialize empty slices 'l' for storing combinations and 'rem' for storing indices
	var l [][]int
	var rem []int

	// Initialize variable 'ans' for storing minimum number of tests
	ans := math.MaxInt32

	// Generate all combinations of indices
	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}

	// Loop through all possible combinations of 'pre' indices
	for i := 0; i <= len(pre); i++ {
		combinations := combinations(pre, i)
		for _, comb := range combinations {
			l = append(l, comb)
		}
	}

	// Loop through each iteration 'i' of test cases
	for i := 0; i < m; i++ {
		// Initialize variable 'ca' to 0 for sum of tests in current combination
		ca := 0

		// Loop through each index 'j' in current combination
		for _, j := range l[i] {
			// Add the test result at index 'j' and test case 'i' to 'ca'
			ca += c[j][i]
		}

		// If the sum of tests in current combination is less than threshold 'x',
		// add the index of the current combination to 'rem' list
		if ca < x {
			rem = append(rem, i)
		}

		// If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
		if len(rem) > 0 {
			for _, j := range rem {
				l = removeIndex(l, j)
			}
			rem = nil
		}

		// If 'l' list is empty, print -1 and break the loop
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}

	// If the loop completes without finding a valid combination,
	// calculate the minimum number of tests in all valid combinations
	for _, comb := range l {
		ca = 0
		for _, j := range comb {
			ca += c[j][0]
		}

		// Update 'ans' with minimum number of tests among all valid combinations
		if ca < ans {
			ans = ca
		}
	}

	// Print the minimum number of tests required
	fmt.Println(ans)
}

// Function to generate combinations
func combinations(arr []int, r int) [][]int {
	var result [][]int
	n := len(arr)
	if r > n {
		return result
	}
	data := make([]int, r)
	var combine func(int, int)
	combine = func(start, index int) {
		if index == r {
			temp := make([]int, r)
			copy(temp, data)
			result = append(result, temp)
			return
		}
		for i := start; i <= n-r+index; i++ {
			data[index] = arr[i]
			combine(i+1, index+1)
		}
	}
	combine(0, 0)
	return result
}

// Function to remove an index from a slice
func removeIndex(s [][]int, index int) [][]int {
	if index < 0 || index >= len(s) {
		return s
	}
	return append(s[:index], s[index+1:]...)
}
