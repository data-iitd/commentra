package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
	var str string // Declare a string variable named str
	fmt.Scan(&str) // Input the string from the user and store it in the string variable str

	// Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes") // Output "Yes" if the conditions are met
	} else {
		fmt.Println("No") // Output "No" if the conditions are not met
	}
}

// <END-OF-CODE>
