
package main

import (
	"fmt"
	"sort"
)

func main() {
	var W string
	fmt.Scan(&W)

	// Step 2: Read input
	// The program reads a string `W` from the standard input.

	// Step 3: Sort the string
	// The string `W` is sorted in ascending order.
	sort.Strings(W)

	// Step 4: Check for character pairs
	// The program iterates through the sorted string, checking if each character
	// is followed by its identical pair.
	for i := 0; i < len(W)-1; i += 2 {
		if W[i] != W[i+1] {
			// If a character is not followed by its pair, output "No" and exit.
			fmt.Println("No")
			return
		}

	}

	// Step 5: Output result
	// If all characters are in pairs, the program outputs "Yes"; otherwise,
	// it outputs "No".
	fmt.Println("Yes")

}

