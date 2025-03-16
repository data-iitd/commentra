package main

import (
	"fmt"
	"strings"
)

const M = 1010

var a, b [M]string
var n, m, ans int

func main() {
	// Read the first string into array 'a' starting from index 1
	fmt.Scan(&a[1])
	// Calculate the length of the first string
	n = len(a[1])
	
	// Read the second string into array 'b' starting from index 1
	fmt.Scan(&b[1])
	// Calculate the length of the second string
	m = len(b[1])
	
	// Initialize the minimum answer to a large value
	ans = M + 10
	
	// Iterate over all possible starting positions in 'a' where 'b' can fit
	for i := 1; i + m - 1 <= n; i++ {
		// Initialize a variable to count the number of mismatches
		sum := 0
		
		// Compare the substring of 'a' with 'b' character by character
		for j := 1; j <= m; j++ {
			// Increment the mismatch count if characters do not match
			if a[1][i+j-1] != b[1][j-1] {
				sum++
			}
		}
		
		// Update the minimum number of mismatches found
		ans = min(ans, sum)
	}
	
	// Output the minimum number of mismatches
	fmt.Println(ans)
}

// Define a function to find the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

