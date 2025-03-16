
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var str1, str2 string
	fmt.Fscanf(reader, "%s %s\n", &str1, &str2)

	// Sort the first string in ascending order
	sort.Strings(str1)

	// Sort the second string in descending order
	sort.Sort(sort.Reverse(sort.StringSlice(str2)))

	// Determine the loop limit based on the length of the shorter string
	loop := len(str1)
	if len(str2) < loop {
		loop = len(str2)
	}
	flag := false

	// Compare characters of the two sorted strings
	for i := 0; loop > i; i++ {
		ch1 := str1[i]
		ch2 := str2[i]

		// If characters match, continue to the next character
		if ch1 == ch2 {
			if loop == i+1 && len(str1) < len(str2) {
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

