package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare character arrays for input strings and temporary storage
	var str, tmp, p string
	
	// Declare integer variables for string lengths and loop control
	var slen, plen int
	var i, flag int
	
	// Read two strings from standard input
	fmt.Scan(&str, &p)
	
	// Copy the original string into a temporary variable and concatenate it with itself
	tmp = str
	str = str + tmp
	
	// Calculate the lengths of the concatenated string and the pattern string
	slen = len(str)
	plen = len(p)
	
	// Initialize a flag to indicate if the pattern is found
	flag = 0
	
	// Loop through the concatenated string to search for the pattern
	for i = 0; i < slen - plen; i++ {
		// Compare the substring of str with the pattern p
		if strings.HasPrefix(str[i:], p) {
			flag = 1 // Set flag if a match is found
		}
	}
	
	// Output "Yes" if the pattern was found, otherwise output "No"
	if flag != 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

