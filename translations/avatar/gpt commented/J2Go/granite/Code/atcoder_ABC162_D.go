
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the integer n which represents the length of the string
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Read the string s which contains characters 'R', 'G', and 'B'
	s := readLine(reader)

	// Initialize counters for each color
	rc := int64(0) // Counter for 'R'
	gc := int64(0) // Counter for 'G'
	bc := int64(0) // Counter for 'B'

	// Count the occurrences of each character in the string
	for _, c := range s {
		switch c {
		case 'R':
			rc++ // Increment red counter
		case 'G':
			gc++ // Increment green counter
		case 'B':
			bc++ // Increment blue counter
		}
	}

	// Calculate the initial result based on the product of the counts
	result := rc * gc * bc

	// Iterate through all pairs of indices (i, k) to check conditions
	for i := 1; i <= n; i++ {
		for k := i + 1; k <= n; k++ {
			// Check if the sum of indices is even
			if (i+k)%2 == 0 {
				// Get the characters at the current indices
				is := s[i-1]
				ks := s[k-1]
				js := s[((i+k)/2)-1]

				// Check if all three characters are different
				if is!= ks && ks!= js && js!= is {
					result-- // Decrease the result if the condition is met
				}
			}
		}
	}

	// Output the final result
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

