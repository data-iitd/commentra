package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize an array of strings called divide
	divide := []string{"dream", "dreamer", "erase", "eraser"}

	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read a string from the standard input
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)

	// Reverse the string S and also reverse each string in the divide array
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

		// Iterate through each string in the divide array
		for _, d := range divide {
			// Check if the substring of S starting from the current index i and having the same size as d is equal to d
			if i+len(d) <= len(S) && S[i:i+len(d)] == d {
				// If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
				can2 = true
				i += len(d)
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

// Helper function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

