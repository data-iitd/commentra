package main

import (
	"fmt"
)

func main() {
	// Initialize scanner to read input from the console
	var n, m int
	fmt.Scan(&n, &m)

	// Read the 2D array 'a' from the input
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	// Initialize variables for binary search tree traversal
	min := int(^uint(0) >> 1)
	var x int
	fmt.Scan(&x)

	// Perform binary tree traversal
	for i := 0; i < 1<<n; i++ {
		status := make([]int, n)

		// Set the status of each node based on the current binary tree node
		for j := 0; j < n; j++ {
			if i&(1<<j) != 0 {
				status[j] = 1
			}
		}

		// Initialize result array for the current binary tree node
		res := make([]int, m+1)

		// Calculate the sum of elements in the current row for each column
		for j := 0; j < n; j++ {
			if status[j] == 1 {
				for k := 0; k <= m; k++ {
					res[k] += a[j][k]
				}
			}
		}

		// Check if the sum of elements in the current row for each column is greater than or equal to 'x'
		flag := true
		for j := 1; j <= m; j++ {
			if res[j] < x {
				flag = false
				break
			}
		}

		// If the sum of elements in all columns for the current binary tree node is greater than or equal to 'x', update the minimum value
		if flag {
			if res[0] < min {
				min = res[0]
			}
		}
	}

	// Print the minimum value if it exists, otherwise print '-1'
	if min == int(^uint(0)>>1) {
		fmt.Println(-1)
	} else {
		fmt.Println(min)
	}
}

