package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	var n, m, x int
	fmt.Scan(&n, &m, &x)
	
	// Initialize a 2D slice to store the input values
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Scan(&a[i][j])
		}
	}
	
	// Initialize the minimum value to the maximum possible integer value
	min := math.MaxInt64
	
	// Iterate through all possible combinations of rows using bit manipulation
	for i := 0; i < int(math.Pow(2, float64(n))); i++ {
		// Create an array to track which rows are included in the current combination
		status := make([]int, n)
		
		// Determine which rows are included in the current combination
		for j := 0; j < n; j++ {
			if (1 & (i >> j)) == 1 {
				status[j] = 1
			}
		}
		
		// Initialize an array to store the sum of the selected rows
		res := make([]int, m+1)
		
		// Calculate the sum of the selected rows
		for j := 0; j < n; j++ {
			if status[j] == 1 {
				for k := 0; k <= m; k++ {
					res[k] += a[j][k]
				}
			}
		}
		
		// Check if the current combination meets the minimum requirement for each column
		flag := true
		for j := 1; j <= m; j++ {
			if res[j] < x {
				flag = false
				break
			}
		}
		
		// If the combination is valid, update the minimum value found
		if flag {
			min = int(math.Min(float64(min), float64(res[0])))
		}
	}
	
	// Output the result: -1 if no valid combination was found, otherwise the minimum value
	if min == math.MaxInt64 {
		fmt.Println(-1)
	} else {
		fmt.Println(min)
	}
}
