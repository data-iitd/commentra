package main

import (
	"fmt"
)

func main() {
	// Initializing variables to hold parts of the input string
	var a, str string
	var n int

	// Reading an integer input which represents the length of the string
	fmt.Scan(&n)
	fmt.Scanln() // Consuming the newline character after the integer input

	// Reading the actual string input
	fmt.Scanln(&str)

	// Loop to construct the first half of the string
	for i := 0; i < n/2; i++ {
		a += string(str[i]) // Appending characters from the first half of the string to 'a'
	}

	// Checking if the string is made up of two identical halves
	if str == a+a {
		fmt.Println("Yes") // If true, print "Yes"
	} else {
		fmt.Println("No") // If false, print "No"
	}
}

// <END-OF-CODE>
