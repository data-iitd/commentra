package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the integer n which represents the length of the string
	scanner.Scan()
	n := len(scanner.Text())
	
	// Read the string s which contains characters 'R', 'G', and 'B'
	scanner.Scan()
	s := scanner.Text()
	
	// Initialize counters for each color
	var rc, gc, bc int64
	
	// Count the occurrences of each character in the string
	for i := 0; i < n; i++ {
		if s[i] == 'R' {
			rc++ // Increment red counter
		} else if s[i] == 'G' {
			gc++ // Increment green counter
		} else {
			bc++ // Increment blue counter
		}
	}
	
	// Calculate the initial result based on the product of the counts
	result := rc * gc * bc
	
	// Iterate through all pairs of indices (i, k) to check conditions
	for i := 1; i <= n; i++ {
		for k := i + 1; k <= n; k++ {
			// Check if the sum of indices is even
			if (i + k) % 2 == 0 {
				// Get the characters at the current indices
				is := s[i - 1]
				ks := s[k - 1]
				js := s[(i + k) / 2 - 1]
				
				// Check if all three characters are different
				if is != ks && ks != js && js != is {
					result-- // Decrease the result if the condition is met
				}
			}
		}
	}
	
	// Output the final result
	fmt.Println(result)
}
