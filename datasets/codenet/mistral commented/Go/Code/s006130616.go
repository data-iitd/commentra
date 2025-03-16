// Package main is the entry point of the program
package main

import "fmt"

func main() {
	// Initialize variables n, m, x for input
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	// Allocate memory for 2D array a and 1D array p
	a := make([][]int, n)
	p := make([]int, n)

	// Read input for p and initialize a with empty rows
	for i := 0; i < n; i++ {
		// Read input for p[i]
		fmt.Scan(&p[i])

		// Allocate memory for row i of a
		a[i] = make([]int, m)

		// Read input for each element of row i of a
		for j := 0; j < m; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	// Initialize variables ans, tot, and ok
	ans := 1200001
	var tot int
	var ok bool

	// Iterate through all possible combinations of bits
	for bits := 0; bits < 1<<n; bits++ {
		// Initialize skill array
		skill := make([]int, m)

		// Calculate total points and update skill array for the current combination of bits
		tot = 0
		ok = true
		for i := 0; i < n; i++ {
			// Check if the current bit is set
			if (bits>>i)&1 == 1 {
				// Add points from p[i] to total
				tot += p[i]

				// Update skill array for each skill
				for j := 0; j < m; j++ {
					skill[j] += a[i][j]
				}
			}
		}

		// Check if the current combination of skills is valid
		for _, v := range skill {
			if v < x {
				ok = false
				break
			}
		}

		// If the current combination is valid, update ans if the total points are less than the current answer
		if ok {
			if ans > tot {
				ans = tot
			}
		}
	}

	// Print the answer
	if ans != 1200001 {
		fmt.Println(ans)
	} else {
		fmt.Println("-1")
	}

}

// "