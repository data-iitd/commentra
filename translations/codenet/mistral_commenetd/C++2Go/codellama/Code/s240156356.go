package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare two string variables and read input from the user
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	// Sort the characters in string str1 in ascending order and in string str2 in descending order
	sort.Strings([]string{str1})
	sort.Sort(sort.Reverse(sort.StringSlice([]string{str2})))

	// Determine the length of the shorter string to be used as the loop limit
	loop := len(str1)
	if len(str2) < loop {
		loop = len(str2)
	}

	// Initialize a boolean flag to false
	flag := false

	// Loop through the characters in both strings up to the length of the shorter string
	for i := 0; loop > i; i++ {
		// Get the characters at the current index in both strings
		ch1 := str1[i]
		ch2 := str2[i]

		// Check if the characters are equal. If they are, check if we have reached the end of the strings
		if ch1 == ch2 {
			// If we have reached the end of str1 and str2 is not empty, set the flag to true and break out of the loop
			if loop == i+1 && len(str1) < len(str2) {
				flag = true
				break
			} else {
				// If we have not reached the end of the strings, continue to the next iteration of the loop
				continue
			}
		} else {
			// If the characters are not equal, compare their ASCII values. If ch2 is greater than ch1, set the flag to true and break out of the loop
			if ch2 > ch1 {
				flag = true
				break
			} else {
				// If ch1 is greater than or equal to ch2, continue to the next iteration of the loop
				break
			}
		}
	}

	// If the flag is true, print "Yes" to the console. Otherwise, print "No" to the console
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

