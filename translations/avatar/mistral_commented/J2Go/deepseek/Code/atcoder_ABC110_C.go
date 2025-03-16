package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	var S, T string

	// Read the first input line from the console
	scanner.Scan()
	S = scanner.Text()

	// Read the second input line from the console
	scanner.Scan()
	T = scanner.Text()

	// Close the Scanner object to save system resources
	defer scanner.Close()

	// Initialize an array of strings A with all possible characters from a to z
	A := []string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}

	// Initialize a boolean variable res to store the result of the comparison
	var res bool = true

	// Iterate through each string s in the array A
	for _, s := range A {
		// Find the index of string s in string S
		sIdx := strings.Index(S, s)

		// If string s is not found in string S, continue to the next string in the array
		if sIdx < 0 {
			continue
		}

		// Convert the character at the index sIdx in string T to a string
		t := string(T[sIdx])

		// Initialize an index variable idx to 0
		idx := 0

		// Iterate through each character in string S starting from the index sIdx
		for idx < len(S) {
			// If string s is found in string S starting from index idx, compare the corresponding characters in strings S and T
			if strings.Index(S[idx:], s) >= 0 {
				if strings.Index(S[idx:], s) != strings.Index(T[idx:], t) {
					// If the characters do not match, set the boolean variable res to false and break out of the loop
					res = false
					break
				} else {
					// If the characters match, increment the index variable idx by the length of string s
					idx = strings.Index(S[idx:], s) + 1
				}
			}

			// If string s is not found in string T starting from index idx, set the boolean variable res to false and break out of the loop
			if strings.Index(T[idx:], t) >= 0 {
				res = false
				break
			}

			// If string s is not found in both strings S and T starting from index idx, break out of the loop
			if strings.Index(S[idx:], s) < 0 && strings.Index(T[idx:], t) < 0 {
				break
			}
		}

		// If the boolean variable res is still true after the loop, print "Yes" to the console
		if res {
			fmt.Println("Yes")
		}

		// If the boolean variable res is false, print "No" to the console and break out of the main loop
		if !res {
			fmt.Println("No")
			break
		}
	}
}
