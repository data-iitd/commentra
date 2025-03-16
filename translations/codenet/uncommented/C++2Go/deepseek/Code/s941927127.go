package main

import (
	"fmt"
	"sort"
)

func main() {
	var W string
	fmt.Scan(&W)

	// Convert the string to a slice of runes to sort it
	runes := []rune(W)
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	// Check if the string can be rearranged to form a palindrome
	canFormPalindrome := true
	for i := 0; i < len(runes); i += 2 {
		if runes[i] != runes[i+1] {
			canFormPalindrome = false
			break
		}
	}

	if canFormPalindrome {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

