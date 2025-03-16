
package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take a string input from the user and store it in the variable `s`
	var s string
	fmt.Scan(&s)

	// Create a Counter object `even` that counts the occurrences of characters at even indices in the string `s`
	even := make(map[string]int)
	for i := 0; i < len(s); i += 2 {
		even[string(s[i])]++
	}

	// Create a Counter object `odd` that counts the occurrences of characters at odd indices in the string `s`
	odd := make(map[string]int)
	for i := 1; i < len(s); i += 2 {
		odd[string(s[i])]++
	}

	// Print the minimum of two possible outcomes:
	// 1. The number of characters that need to be flipped to make all even characters '0' and the number of characters that need to be flipped to make all even characters '1', or vice versa.
	fmt.Println(min(len(s)-(even["0"]+odd["1"]), len(s)-(even["1"]+odd["0"])))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

