package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the length of the string")
	// Read the length of the string
	length, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the string")
	// Read the string
	s := reader.ReadString('\n')
	// Initialize counters for each color
	rc := 0
	gc := 0
	bc := 0
	// Count the occurrences of each character in the string
	for _, c := range s {
		if c == 'R' {
			rc++
		} else if c == 'G' {
			gc++
		} else {
			bc++
		}
	}
	// Calculate the initial result based on the product of the counts
	result := rc * gc * bc
	// Iterate through all pairs of indices (i, k) to check conditions
	for i := 1; i <= length; i++ {
		for k := i + 1; k <= length; k++ {
			// Check if the sum of indices is even
			if (i+k)%2 == 0 {
				// Get the characters at the current indices
				is := s[i-1]
				ks := s[k-1]
				js := s[((i+k)/2)-1]
				// Check if all three characters are different
				if is!= ks && ks!= js && js!= is {
					result--
				}
			}
		}
	}
	// Output the final result
	fmt.Println(result)
}

