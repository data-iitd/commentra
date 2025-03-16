
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Take input from the user
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')

	// Initialize an empty list to store the result
	res := []string{}

	// Define a list of punctuation marks to check against
	punctuation := []string{",", ".", "!", "?"}

	// Iterate through each character in the input string
	for i := 0; i < len(s); i++ {
		// Check if the current index is greater than or equal to 1
		if i >= 1 {
			// If the current character is a space
			if s[i] =='' {
				// Only append a space if the last element in res is not a space
				if res[len(res)-1]!= "" {
					res = append(res, s[i])
				} else {
					continue // Skip if the last element is already a space
				}
			} else {
				// If the current character is a punctuation mark
				if contains(punctuation, string(s[i])) {
					// If the last element in res is a space, remove it
					if res[len(res)-1] == "" {
						res = res[:len(res)-1]
					}
					// Append the punctuation mark to the result
					res = append(res, string(s[i]))
					// Append a space after the punctuation
					res = append(res, " ")
				} else {
					// If the current character is not punctuation, append it to the result
					res = append(res, string(s[i]))
				}
			}
		} else {
			// For the first character, handle it separately
			if s[i] =='' {
				continue // Skip if it's a space
			}
			if contains(punctuation, string(s[i])) {
				continue // Skip if it's a punctuation mark
			} else {
				// Append the first character to the result if it's not a space or punctuation
				res = append(res, string(s[i]))
			}
		}
	}

	// Join the list into a single string and print the result
	fmt.Println(strings.Join(res, ""))
}

func contains(s []string, e string) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

