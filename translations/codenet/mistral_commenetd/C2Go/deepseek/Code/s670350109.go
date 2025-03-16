package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1, str2, temp string
	var i, j, t int

	// Read the first string from the user
	fmt.Scanln(&str1)
	fmt.Println("First string:", str1) // Print the first string for verification

	// Read the second string from the user
	fmt.Scanln(&str2)
	fmt.Println("Second string:", str2) // Print the second string for verification

	i = len(str1) // Get the length of the first string
	t = i - 1     // Set the index variable t to the last index of the first string

	// Check if the lengths of the two strings are equal
	if len(str1) != len(str2) {
		fmt.Println("NO") // If the lengths are not equal, print "NO" and exit
	} else {
		// Reverse the first string and store it in temp string
		temp = ""
		for j = len(str1) - 1; j >= 0; j-- {
			temp += string(str1[j]) // Append the characters to temp in reverse order
		}

		// Compare the reversed first string with the second string
		t = 0
		for i := 0; i < len(temp); i++ {
			if temp[i] == str2[i] {
				t++ // Increment the counter if they are equal
			}
		}

		// Check if all characters are equal and print the result accordingly
		if len(str2) == t {
			fmt.Println("YES") // If all characters are equal, print "YES"
		} else {
			fmt.Println("NO") // If any character is different, print "NO"
		}
	}
}

