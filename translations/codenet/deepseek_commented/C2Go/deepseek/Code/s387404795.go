package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, tmp, p string
	var slen, plen int
	var i, flag int
	
	// Read two strings from the user
	fmt.Scan(&str, &p)
	
	// Duplicate and concatenate the string
	tmp = str
	str = str + tmp
	
	// Calculate the lengths of the strings
	slen = len(str)
	plen = len(p)
	
	// Initialize flag to 0 (not found)
	flag = 0
	
	// Check if the pattern exists in the concatenated string
	for i = 0; i < slen - plen; i++ {
		if strings.HasPrefix(str[i:], p) {
			flag = 1
		}
	}
	
	// Output the result
	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

