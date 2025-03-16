package main // Defining the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() { // Defining the main function
	var str string // Declaring a string variable to hold the input
	var k int64   // Declaring a variable to hold the long integer input

	fmt.Scan(&str) // Reading the first line of input as a string
	fmt.Scan(&k)   // Reading the second line of input as a long integer

	c := []rune(str) // Converting the string to a slice of runes (characters)
	n := len(c)      // Finding the length of the string

	for i := int64(0); i < k; i++ { // Starting a for loop to iterate through the character slice up to the given limit 'k'
		if c[i] == '1' { // Checking if the current character is '1'
			if i == k-1 { // Checking if the current index is the last index of the slice
				fmt.Println(1) // If yes, print '1' and exit the function
				return
			}
		} else {
			fmt.Println(string(c[i])) // If the current character is not '1', print it to the console
			return // Exit the function as soon as a non-'1' character is found
		}
	}
}

// <END-OF-CODE>
