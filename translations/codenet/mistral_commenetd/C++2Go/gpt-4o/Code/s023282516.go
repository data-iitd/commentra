package main

import (
	"fmt"
	"strings"
)

func main() {
	// Initialize a slice of strings called divide
	divide := []string{"dream", "dreamer", "erase", "eraser"}

	// Declare a string variable called S and read a string from the standard input
	var S string
	fmt.Scan(&S)

	// Reverse the string S and also reverse each string in the divide slice
	S = reverseString(S)
	for i := range divide {
		divide[i] = reverseString(divide[i])
	}

	// Initialize a boolean variable called can to true
	can := true

	// Iterate through each character in the string S
	for i := 0; i < len(S); {
		// Initialize a boolean variable called can2 to false
		can2 := false

		// Iterate through each string in the divide slice
		for _, d := range divide {
			// Check if the substring of S starting from the current index i and having the same size as d is equal to d
			if strings.HasPrefix(S[i:], d) {
				// If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
				can2 = true
				i += len(d)
				break // Break to avoid checking other strings once a match is found
			}
		}

		// If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
		if !can2 {
			can = false
			break
		}
	}

	// Output "YES" if can is true, otherwise output "NO"
	if can {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// Function to reverse a string
func reverseString(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>
