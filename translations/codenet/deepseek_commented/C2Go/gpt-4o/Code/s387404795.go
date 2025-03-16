package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, p string

	// Read two strings from the user
	fmt.Scan(&str, &p)

	// Duplicate and concatenate the string
	tmp := str
	str += tmp

	// Calculate the lengths of the strings
	slen := len(str)
	plen := len(p)

	// Initialize flag to false (not found)
	flag := false

	// Check if the pattern exists in the concatenated string
	for i := 0; i <= slen-plen; i++ {
		if str[i:i+plen] == p {
			flag = true
			break
		}
	}

	// Output the result
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
