package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	// Taking input from the user and splitting it into two integers
	// Assigning the values to variables `n` and `k`

	M := make([]int, n)
	var input string
	fmt.Scan(&input)
	// Taking another input from the user, which is supposed to be a list of integers
	// Converting each input into an integer and storing them in the list `M`
	for i, val := range strings.Split(input, " ") {
		M[i], _ = strconv.Atoi(val)
	}

	m := 0
	// Initializing a variable `m` to 0

	for j := 0; j < n; j++ {
		// Starting a loop that will iterate `n` times
		var p int
		for p = 0; p < n; p++ {
			// Starting another loop that will iterate `n` times
			if M[p] == 0 {
				// Checking if the element at position `p` in the list `M` is 0
				fmt.Print(p + 1, " ")
				// If the condition is true, print the position `p + 1`
				break
				// Break out of the loop after printing the position
			}
		}
		for l := 0; l < p+1-k; l++ {
			M[l]--
		}
		// Decreasing the elements in the list `M` from position 0 to `p - k` by 1
		M[p]--
		// Decreasing the element at position `p` by 1
	}
}
// <END-OF-CODE>
