package main

import "fmt"

func main() {
	// Declare variables for the number of participants (n), number of skills (m), and the minimum skill level required (x)
	var n, m, x int
	// Read input values for n, m, and x
	fmt.Scan(&n, &m, &x)

	// Initialize a 2D slice to hold skill levels and a slice for participant points
	a := make([][]int, n)
	p := make([]int, n)
	// Read participant points and their respective skill levels
	for i := 0; i < n; i++ {
		// Read the points for participant i
		fmt.Scan(&p[i])
		// Initialize the skill level slice for participant i
		a[i] = make([]int, m)
		// Read the skill levels for participant i
		for j := 0; j < m; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	// Initialize the answer to a large number and other variables for tracking total points and skill validation
	ans := 1200001
	var tot int
	var ok bool

	// Iterate through all possible combinations of participants using bit manipulation
	for bits := 0; bits < 1<<n; bits++ {
		// Reset total points and skill validation flag for the current combination
		tot = 0
		ok = true
		// Initialize a slice to accumulate skill levels for the current combination
		skill := make([]int, m)

		// Check each participant to see if they are included in the current combination
		for i := 0; i < n; i++ {
			if (bits>>i)&1 == 1 {
				// Add the points of the selected participant to the total
				tot += p[i]
				// Accumulate the skill levels of the selected participant
				for j := 0; j < m; j++ {
					skill[j] += a[i][j]
				}
			}
		}

		// Check if the accumulated skill levels meet the minimum requirement
		for _, v := range skill {
			if v < x {
				ok = false // If any skill level is below x, mark as not okay
				break
			}
		}

		// If the combination is valid (all skills meet the requirement), update the answer if the total points are lower
		if ok {
			if ans > tot {
				ans = tot
			}
		}
	}

	// Output the result: the minimum points needed or -1 if no valid combination was found
	if ans != 1200001 {
		fmt.Println(ans)
	} else {
		fmt.Println("-1")
	}
}
