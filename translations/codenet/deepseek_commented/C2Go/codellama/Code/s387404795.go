package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, p string
	var slen, plen int
	var flag bool
	
	// Read two strings from the user
	fmt.Scan(&str, &p)
	
	// Duplicate and concatenate the string
	str += str
	
	// Calculate the lengths of the strings
	slen = len(str)
	plen = len(p)
	
	// Initialize flag to 0 (not found)
	flag = false
	
	// Check if the pattern exists in the concatenated string
	for i := 0; i < slen - plen; i++ {
		if strings.HasPrefix(str[i:], p) {
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

