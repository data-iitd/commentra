package main

import (
	"fmt"
)

const INF = 1 << 29
const MOD = 1000000007

func main() {
	// Read the number of elements and the constant c
	var n, c int64
	fmt.Scan(&n, &c)

	// Initialize slices to store positions and velocities
	x := make([]int64, n+1)
	v := make([]int64, n+1)

	// Read the positions and velocities of the elements
	for i := int64(1); i <= n; i++ {
		fmt.Scan(&x[i], &v[i])
	}

	// Initialize slices to store cumulative velocities from the left
	lefttotal := make([]int64, n+1)
	maxlefttotal := make([]int64, n+1)

	// Calculate cumulative velocities from the left
	for i := int64(1); i <= n; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	// Calculate the maximum value of lefttotal adjusted by position
	for i := int64(1); i <= n; i++ {
		maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
	}

	// Initialize slices to store cumulative velocities from the right
	righttotal := make([]int64, n+1)
	maxrighttotal := make([]int64, n+1)

	// Calculate cumulative velocities from the right
	for i := int64(1); i <= n; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	// Calculate the maximum value of righttotal adjusted by position
	for i := int64(1); i <= n; i++ {
		maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i]-(c-x[n+1-i]))
	}

	// Initialize the answer variable to store the maximum result
	var ans int64 = 0

	// Evaluate the maximum possible value based on different scenarios
	for i := int64(1); i <= n; i++ {
		ans = max(ans, lefttotal[i]-x[i])                             // Scenario 1
		ans = max(ans, lefttotal[i]-2*x[i]+maxrighttotal[n-i])     // Scenario 2
		ans = max(ans, righttotal[i]-(c-x[n+1-i]))                  // Scenario 3
		ans = max(ans, righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]) // Scenario 4
	}

	// Output the final result
	fmt.Println(ans)
}

// max function to return the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
