package main

import (
	"fmt"
	"strings"
)

func main() {
	var a int
	var taro, hana string
	var t, h int

	fmt.Scan(&a) // Read number of strings from user

	for i := 0; i < a; i++ { // Loop through each string pair
		fmt.Scan(&taro, &hana) // Read two strings from user
		lt := len(taro)         // Get length of first string
		lh := len(hana)         // Get length of second string

		if lt > lh { // Check if first string is longer
			l = lt // Set length to be the maximum length
		} else {
			l = lh // Set length to be the minimum length
		}

		tt := 0 // Initialize variables for comparing characters
		hh := 0

		if strings.Compare(taro, hana) > 0 { // Check if first string is greater lexicographically
			t = t + 3 // Increment t if true
		} else if strings.Compare(hana, taro) > 0 {
			h = h + 3 // Increment h if true
		} else if taro == hana { // Check if strings are equal
			h = h + 1 // Increment h if true
			t = t + 1 // Increment t if true
		}
	}

	fmt.Println(t, h) // Output the result
}

