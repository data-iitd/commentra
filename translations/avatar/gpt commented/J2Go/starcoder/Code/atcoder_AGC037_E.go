package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	sc := bufio.NewScanner(os.Stdin)

	// The first line contains the length of the string and the number of operations
	var N, K int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	K, _ = strconv.Atoi(sc.Text())

	// The second line contains the initial string
	var S string
	sc.Scan()
	S = sc.Text()

	// Flag to check if we are processing the first iteration
	firstTime := true
	// Variable to control the step size for substring extraction
	step := 1

	// Loop until K operations are performed
	for K > 0 {
		// Create a reversed copy of the current string S
		T := reverse(S)

		// Create a new string that combines S and its reverse, then reverse it
		revU := reverse(S + T)
		revU = reverse(revU)

		// Initialize a variable to keep track of the best string found so far
		sDash := S

		// Iterate through the string revU to find the lexicographically smallest substring
		for i := N; i >= 0; i -= step {
			// Extract a substring from revU
			tmp := revU[i : i+N]

			// Compare and update sDash if a smaller substring is found
			if sDash > tmp {
				sDash = tmp
			} else {
				// If we are not in the first iteration, break the loop
				if!firstTime {
					break
				}
			}
		}

		// If this is the first iteration, check if we can print a uniform string
		if firstTime {
			firstTime = false
			// If 2^K is greater than N, print the first character of sDash N times
			if math.Pow(2, float64(K)) > float64(N) {
				fmt.Printf("%s\n", sDash[0:N])
				os.Exit(0)
			}
		} else {
			// Increase the step size for the next iteration
			step += step
		}

		// Decrement K and update S for the next operation
		K--
		S = reverse(sDash)
	}

	// Print the final result after all operations
	fmt.Printf("%s\n", reverse(S))
}

// reverse returns a reversed copy of a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// 