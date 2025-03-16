package main

import (
	"fmt"
	"sort"
)

func main() {
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	// Convert strings to slices of runes for sorting
	runes1 := []rune(str1)
	runes2 := []rune(str2)

	// Sort the first string in ascending order
	sort.Slice(runes1, func(i, j int) bool {
		return runes1[i] < runes1[j]
	})

	// Sort the second string in descending order
	sort.Slice(runes2, func(i, j int) bool {
		return runes2[i] > runes2[j]
	})

	// Determine the loop limit based on the length of the shorter string
	loop := len(runes1)
	if len(runes2) < loop {
		loop = len(runes2)
	}
	flag := false

	// Compare characters of the two sorted strings
	for i := 0; i < loop; i++ {
		ch1 := runes1[i]
		ch2 := runes2[i]

		// If characters match, continue to the next character
		if ch1 == ch2 {
			if loop == i+1 && len(runes1) < len(runes2) {
				flag = true
				break
			} else {
				continue
			}
		} else {
			// If characters do not match, check if the character from the second string is greater
			if ch2 > ch1 {
				flag = true
				break
			} else {
				break
			}
		}
	}

	// Check the flag and print the result
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
