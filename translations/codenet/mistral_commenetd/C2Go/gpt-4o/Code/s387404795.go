package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
	"strings" // Import the strings package for string manipulation
)

func main() { // Declare the main function
	var str, p string // Declare two string variables, str and p

	fmt.Scan(&str, &p) // Read two strings from the standard input and store them in str and p respectively

	tmp := str // Copy the contents of str to tmp
	str += tmp // Concatenate the contents of str and tmp, i.e., str now contains str concatenated with itself

	slen := len(str) // Get the length of str and store it in slen
	plen := len(p) // Get the length of p and store it in plen

	flag := false // Initialize flag to false
	for i := 0; i <= slen-plen; i++ { // Iterate through the string str from the beginning to the end - plen characters
		if str[i:i+plen] == p { // Compare the substring of str starting from index i with length plen to p
			flag = true // If the comparison is successful, set flag to true
			break // Exit the loop as we found a match
		}
	}

	if flag { // If flag is true
		fmt.Println("Yes") // Print "Yes" to the standard output
	} else {
		fmt.Println("No") // If flag is false, print "No" to the standard output
	}
}

// <END-OF-CODE>
