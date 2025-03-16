package main

import (
	"fmt"
	"math"
	"os"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the integer N (length of the string) and K (number of operations)
	var N int
	var K int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &N)
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &K)

	// Read the initial string and create a StringBuilder for manipulation
	S := strings.Builder{}
	sc.Scan()
	S.WriteString(sc.Text())

	// Flag to check if we are processing the first iteration
	firstTime := true
	// Variable to control the step size for substring extraction
	step := 1

	// Loop until K operations are performed
	for K > 0 {
		// Create a reversed copy of the current string S
		T := strings.Builder{}
		T.WriteString(S.String())
		T.Reverse()

		// Create a new StringBuilder that combines S and its reverse, then reverse it
		revU := strings.Builder{}
		revU.WriteString(S.String() + T.String())
		revU.Reverse()

		// Initialize a variable to keep track of the best string found so far
		sDash := S.String()

		// Iterate through the string revU to find the lexicographically smallest substring
		for i := N; i >= 0; i -= step {
			// Extract a substring from revU
			tmp := revU.String()[i : i+N]

			// Compare and update sDash if a smaller substring is found
			if sDash > tmp {
				sDash = tmp
			} else {
				// If we are not in the first iteration, break the loop
				if !firstTime {
					break
				}
			}
		}

		// If this is the first iteration, check if we can print a uniform string
		if firstTime {
			firstTime = false
			// If 2^K is greater than N, print the first character of sDash N times
			if math.Pow(2, float64(K)) > float64(N) {
				c := sDash[0]
				for i := 0; i < N; i++ {
					fmt.Printf("%c", c)
				}
				fmt.Println()
				os.Exit(0)
			}
		} else {
			// Increase the step size for the next iteration
			step += step
		}

		// Decrement K and update S for the next operation
		K--
		S = strings.Builder{}
		S.WriteString(sDash)
		S.Reverse()
	}

	// Print the final result after all operations
	fmt.Println(S.Reverse())
}

