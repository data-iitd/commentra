package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	// Create a scanner object to read input from the console
	var N, K int
	var S string
	fmt.Scan(&N, &K)
	fmt.Scan(&S)
	
	// Flag to check if we are processing the first iteration
	firstTime := true
	// Variable to control the step size for substring extraction
	step := 1
	
	// Loop until K operations are performed
	for K > 0 {
		// Create a reversed copy of the current string S
		T := reverseString(S)
		
		// Create a new string that combines S and its reverse, then reverse it
		revU := S + T
		revU = reverseString(revU)
		
		// Initialize a variable to keep track of the best string found so far
		sDash := S
		
		// Iterate through the string revU to find the lexicographically smallest substring
		for i := N; i >= 0; i -= step {
			// Extract a substring from revU
			tmp := revU[i : i+N]
			
			// Compare and update sDash if a smaller substring is found
			if strings.Compare(sDash, tmp) > 0 {
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
					fmt.Print(string(c))
				}
				fmt.Println()
				return
			}
		} else {
			// Increase the step size for the next iteration
			step += step
		}
		
		// Decrement K and update S for the next operation
		K--
		S = sDash
		S = reverseString(S)
	}
	
	// Print the final result after all operations
	fmt.Println(reverseString(S))
}

// Helper function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

