package main

import (
	"fmt"
)

func main() {
	var a int
	var t, h int // Initialize variables

	fmt.Scan(&a) // Read number of strings from user

	for i := 0; i < a; i++ { // Loop through each string pair
		var taro, hana string
		fmt.Scan(&taro, &hana) // Read two strings from user

		lt := len(taro) // Get length of first string
		lh := len(hana) // Get length of second string

		var l int
		if lt > lh { // Check if first string is longer
			l = lt // Set length to be the maximum length
		} else {
			l = lh // Set length to be the minimum length
		}

		if taro > hana { // Check if first string is greater lexicographically
			t += 3 // Increment t if true
		} else if hana > taro {
			h += 3 // Increment h if true
		} else if hana == taro { // Check if strings are equal
			h++ // Increment h if true
			t++ // Increment t if true
		}
	}

	fmt.Println(t, h) // Output the result
}

// <END-OF-CODE>
