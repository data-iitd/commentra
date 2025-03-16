package main

import (
	"fmt"
)

func main() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)

	rc, gc, bc := int64(0), int64(0), int64(0) // Initializing counts for 'R', 'G', and other characters

	for i := 0; i < len(s); i++ { // Iterating through each character in the string
		switch s[i] {
		case 'R':
			rc++ // Incrementing the count for 'R' characters
		case 'G':
			gc++ // Incrementing the count for 'G' characters
		default:
			bc++ // Incrementing the count for other characters
		}
	}

	result := rc * gc * bc // Calculating the initial result

	for i := 1; i <= n; i++ { // Iterating through each pair of indices in the string
		for k := i + 1; k <= n; k++ { // Nested loop for pairs of indices
			if (i+k)%2 == 0 { // Checking if the sum of the indices is even
				is := s[i-1] // Character at index i-1
				ks := s[k-1] // Character at index k-1
				js := s[(i+k)/2-1] // Character at the midpoint
				if is != ks && ks != js && js != is { // Checking if the characters are different
					result-- // Decrementing the result if they are
				}
			}
		}
	}

	fmt.Println(result) // Printing the final result
}

// <END-OF-CODE>
