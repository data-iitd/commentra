package main

import (
	"fmt"
	"math"
)

const M = 1010 // Step 2: Define constant for string length

func main() {
	var a, b string // Step 2: Define variables to store input strings
	var n, m int
	ans := M + 10 // Step 2: Define variable for minimum differences

	// Step 3: Read input strings
	fmt.Scan(&a) // Read and store the string a
	n = len(a)   // Get the length of string a
	fmt.Scan(&b) // Read and store the string b
	m = len(b)   // Get the length of string b

	// Step 4: Calculate the minimum number of differences
	for i := 0; i+m <= n; i++ { // Iterate over possible starting positions
		sum := 0 // Initialize sum of differences for current starting position
		for j := 0; j < m; j++ { // Compare each character of b with corresponding character in a
			if a[i+j] != b[j] { // Check if characters are different
				sum++ // Increment sum if characters are different
			}
		}
		ans = int(math.Min(float64(ans), float64(sum))) // Update minimum differences
	}

	// Step 5: Output the result
	fmt.Println(ans) // Print the minimum number of differences
}

// <END-OF-CODE>
