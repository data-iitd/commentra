package main

import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Read input
	var W string
	fmt.Scan(&W)

	// Step 2: Convert string to a slice of runes for sorting
	runes := []rune(W)

	// Step 3: Sort the runes
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	// Step 4: Check for character pairs
	for i := 0; i < len(runes); i += 2 {
		if i+1 >= len(runes) || runes[i] != runes[i+1] {
			// If a character is not followed by its pair, output "No" and exit.
			fmt.Println("No")
			return
		}
	}

	// Step 5: Output result
	// If all characters are in pairs, the program outputs "Yes".
	fmt.Println("Yes")
}

// <END-OF-CODE>
