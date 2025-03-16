package main

import (
	"fmt"
	"sort"
)

func main() {
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	// Sort the first string in ascending order
	sort.Slice(str1, func(i, j int) bool {
		return str1[i] < str1[j]
	})

	// Sort the second string in descending order
	sort.Slice(str2, func(i, j int) bool {
		return str2[i] > str2[j]
	})

	// Determine the loop limit based on the length of the shorter string
	loop := len(str1)
	if len(str2) < loop {
		loop = len(str2)
	}
	flag := false

	// Compare characters of the two sorted strings
	for i := 0; i < loop; i++ {
		ch1 := str1[i]
		ch2 := str2[i]

		// If characters match, continue to the next character
		if ch1 == ch2 {
			if i == loop-1 && len(str1) < len(str2) {
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

