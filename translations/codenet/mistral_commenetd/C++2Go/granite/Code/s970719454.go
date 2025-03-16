

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Including necessary headers
	//...

	// Defining macros for for loops
	//...

	// Initializing arrays
	here := make([]int, 100001)
	dp1 := make([]int, 100001)
	dp2 := make([]int, 100001)

	// Initializing all elements of the arrays to zero
	for i := 0; i < 100001; i++ {
		here[i] = dp1[i] = dp2[i] = 0
	}

	// Reading input
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		if line == "0 0" {
			break
		}

		// Resetting the arrays for new input
		for i := 0; i < 100001; i++ {
			here[i] = dp1[i] = dp2[i] = 0
		}

		// Reading number of houses and queries
		dpflg := false

		// Reading queries
		tokens := strings.Split(line, " ")
		n, _ := strconv.Atoi(tokens[0])
		m, _ := strconv.Atoi(tokens[1])

		for i := 0; i < m; i++ {
			a, _ := strconv.Atoi(tokens[i+2])
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
		if!dpflg {
			fmt.Println(maxi1)
		} else {
			fmt.Println(maxi2)
		}
	}
}

