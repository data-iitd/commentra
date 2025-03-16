package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	// Sort the first string in ascending order
	str1Slice := strings.Split(str1, "")
	sort.Strings(str1Slice)
	str1 = strings.Join(str1Slice, "")

	// Sort the second string in descending order
	str2Slice := strings.Split(str2, "")
	sort.Sort(sort.Reverse(sort.StringSlice(str2Slice)))
	str2 = strings.Join(str2Slice, "")

	// Determine the loop limit based on the length of the shorter string
	loop := len(str1)
	if len(str2) < len(str1) {
		loop = len(str2)
	}
	flag := false

	// Compare characters of the two sorted strings
	for i := 0; i < loop; i++ {
		ch1 := str1[i]
		ch2 := str2[i]

		// If characters match, continue to the next character
		if ch1 == ch2 {
			if loop == i+1 && len(str1) < len(str2) {
				flag = true
				break
			}
			continue
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
