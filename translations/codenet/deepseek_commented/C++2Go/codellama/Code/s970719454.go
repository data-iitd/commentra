package main

import (
	"fmt"
)

func main() {
	// Main loop to read input values
	for {
		var n, m int
		fmt.Scan(&n, &m)
		if n == 0 {
			break
		}

		// Initialize arrays for each iteration
		here := make([]int, 100001)
		dp1 := make([]int, 100001)
		dp2 := make([]int, 100001)

		// Flag to determine behavior based on input
		dpflg := false

		// Read m values and mark them in 'here'
		for i := 0; i < m; i++ {
			var a int
			fmt.Scan(&a)
			if a == 0 {
				dpflg = true
			}
			here[a] = 1
		}

		// Variables to store maximum lengths of sequences
		maxi1 := 0
		maxi2 := 0

		// Calculate maximum length of sequences in dp1
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1
			}
			if dp1[i] > maxi1 {
				maxi1 = dp1[i]
			}
		}

		// Calculate maximum length of sequences in dp2
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

		// Output the result based on the value of dpflg
		if !dpflg {
			fmt.Println(maxi1)
		} else {
			fmt.Println(maxi2)
		}
	}
}

