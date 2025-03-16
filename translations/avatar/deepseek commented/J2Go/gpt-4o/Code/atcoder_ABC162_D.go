package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the integer n
	var s string
	fmt.Scan(&s) // Read the string s

	var rc, gc, bc int64 // Counters for 'R', 'G', and 'B' characters

	// Count the number of 'R', 'G', and 'B' characters in the string s
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case 'R':
			rc++
		case 'G':
			gc++
		case 'B':
			bc++
		}
	}

	result := rc * gc * bc // Calculate the initial product of counts

	// Iterate through possible pairs of indices i and k where i < k
	for i := 1; i <= n; i++ {
		for k := i + 1; k <= n; k++ {
			if (i+k)%2 == 0 { // Check if the sum of indices is even
				is := s[i-1] // Character at index i-1
				ks := s[k-1] // Character at index k-1
				js := s[(i+k)/2-1] // Character at the middle index

				// Check if the characters are all different and not equal to each other
				if is != ks && ks != js && js != is {
					result-- // Decrement the result if conditions are met
				}
			}
		}
	}

	fmt.Println(result) // Print the final result
}

// <END-OF-CODE>
