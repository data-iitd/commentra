
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize scanner to read input from standard input
	sc := bufio.NewScanner(os.Stdin)

	// Main method is the entry point of the Go application
	func() {
		// Read the first integer N from the standard input
		var N int
		fmt.Fscanln(sc, &N)

		// Read the second integer K from the standard input
		var K int
		fmt.Fscanln(sc, &K)

		// Read the string S from the standard input
		var S string
		fmt.Fscanln(sc, &S)

		// Initialize a boolean variable firstTime to true
		var firstTime bool = true

		// Initialize an integer variable step to 1
		var step int = 1

		// Perform the main logic while K is greater than zero
		for K > 0 {
			// Create a new string T to store the reversed version of S
			var T string = reverse(S)

			// Create a new string revU to store the concatenation of S and T reversed
			var revU string = reverse(S + T)

			// Create a string variable sDash to store the current substring of revU
			var sDash string = S

			// Iterate through the substrings of revU starting from the end of S
			for i := N; i >= 0; i -= step {
				// Get the substring of revU starting from the current index i and of length N
				tmp := revU[i : i+N]

				// Compare the current substring tmp with the current substring sDash
				if sDash > tmp {
					// Update the current substring sDash with the new substring tmp
					sDash = tmp
				} else {
					// If this is not the first iteration, break the loop
					if!firstTime {
						break
					}
				}
			}

			// Perform some actions based on the comparison of sDash and S
			if firstTime {
				firstTime = false
				// Check if the length of S raised to the power of K is greater than N
				if math.Pow(2, float64(K)) > float64(N) {
					// Print the first character of S N times and exit the program
					for i := 0; i < N; i++ {
						fmt.Print(sDash[0])
					}
					fmt.Println()
					os.Exit(0)
				}
			} else {
				// Update the value of step
				step += step
			}

			// Decrement the value of K
			K--

			// Update the value of S to be the current substring sDash reversed
			S = reverse(sDash)
		}

		// Print the reversed version of the final string S
		fmt.Println(reverse(S))
	}()

	// Close the scanner to release the system resources
	sc.Close()
}

// reverse returns the reverse of a string
func reverse(s string) string {
	// Create a new string to store the reversed version of s
	var r string = ""

	// Iterate through the characters of s
	for i := len(s) - 1; i >= 0; i-- {
		// Append the current character to the new string
		r += s[i : i+1]
	}

	// Return the new string
	return r
}

