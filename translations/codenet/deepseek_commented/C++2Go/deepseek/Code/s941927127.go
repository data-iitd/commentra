package main

import (
	"fmt"
	"sort"
)

func main() {
	var W string
	fmt.Scan(&W)

	// Sort the string
	runes := []rune(W)
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})
	W = string(runes)

	// Check for character pairs
	for i := 0; i < len(W); i += 2 {
		if i+1 >= len(W) || W[i] != W[i+1] {
			// If a character is not followed by its pair, output "No" and exit.
			fmt.Println("No")
			return
		}
	}

	// Output result
	fmt.Println("Yes")
}

