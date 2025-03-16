package main

import (
	"fmt"
)

func main() {
	// Initializing arrays
	const size = 100001
	here := make([]int, size)
	dp1 := make([]int, size)
	dp2 := make([]int, size)

	// Reading input
	for {
		var n, m int
		fmt.Scan(&n, &m)
		if n == 0 {
			break
		}

		// Resetting the arrays for new input
		for i := 0; i < size; i++ {
			here[i] = 0
			dp1[i] = 0
			dp2[i] = 0
		}

		// Reading number of houses and queries
		dpflg := false

		// Reading queries
		for i := 0; i < m; i++ {
			var a int
			fmt.Scan(&a)
			// Setting the corresponding element of 'here' array to 1
			here[a] = 1
			// If a query is to find the maximum length of a subsequence without any house, then setting 'dpflg' to true
			if a == 0 {
				dpflg = true
			}
		}

		// Calculating the maximum length of a subsequence without any house
		maxi1 := 0
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1
			}
			if dp1[i] > maxi1 {
				maxi1 = dp1[i]
			}
		}

		// Calculating the maximum length of a subsequence with at least one house
		maxi2 := 0
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp2[i] = dp2[i-1] + 1
			} else {
				dp2[i] = dp1[i-1] + 1
			}
			if dp2[i] > maxi2 {
				maxi2 = dp2[i]
			}
		}

		// Printing the result
		if !dpflg {
			fmt.Println(maxi1)
		} else {
			fmt.Println(maxi2)
		}
	}
}

// <END-OF-CODE>
