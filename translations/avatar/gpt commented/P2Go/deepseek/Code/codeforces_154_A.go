package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the main string from user input
	s, _ := reader.ReadString('\n')
	
	// Read the number of subsequent strings to process
	var n int
	fmt.Scanln(&n)
	
	// Initialize the answer variable to accumulate results
	ans := 0
	
	// Loop through each of the n strings provided by the user
	for i := 0; i < n; i++ {
		// Read the current string
		x, _ := reader.ReadString('\n')
		
		// Initialize counters for characters matching the first and second characters of x
		a, b := 0, 0
		
		// Loop through each character in the main string s
		for _, j := range s {
			// If the character matches the first character of x, increment counter a
			if string(j) == string(x[0]) {
				a++
			} else if string(j) == string(x[1]) {
				b++
			} else {
				// If a character does not match either, add the minimum of a and b to ans
				ans += min(a, b)
				// Reset counters a and b for the next segment
				a, b = 0, 0
			}
		}
		
		// After finishing the loop, add the minimum of a and b to ans for the last segment
		ans += min(a, b)
	}
	
	// Print the final accumulated answer
	fmt.Println(ans)
}

// Helper function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

