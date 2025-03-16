
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the integer N (length of the string) and K (number of operations)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	K, _ := strconv.Atoi(sc.Text())

	// Read the initial string and create a StringBuilder for manipulation
	sc.Scan()
	S := sc.Text()

	// Flag to check if we are processing the first iteration
	firstTime := true
	// Variable to control the step size for substring extraction
	step := 1

	// Loop until K operations are performed
	for K > 0 {
		// Create a reversed copy of the current string S
		T := reverse(S)

		// Create a new StringBuilder that combines S and its reverse, then reverse it
		revU := reverse(S + T)

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
			if pow(2, K) > N {
				c := string(sDash[0])
				for i := 0; i < N; i++ {
					fmt.Print(c)
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
		S = sDash
	}

	// Print the final result after all operations
	fmt.Println(reverse(S))
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func pow(x, n int) int {
	result := 1
	for i := 0; i < n; i++ {
		result *= x
	}
	return result
}

