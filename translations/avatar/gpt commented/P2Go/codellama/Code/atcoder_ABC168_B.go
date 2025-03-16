package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read an integer input K from the user
	var K int
	fmt.Scan(&K)

	// Read a string input S from the user
	var S string
	fmt.Scan(&S)

	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {
		// If true, return the original string S
		fmt.Println(S)
	} else {
		// If the length of S is greater than K, return the first K characters followed by '...'
		fmt.Println(S[:K] + "...")
	}
}

// 