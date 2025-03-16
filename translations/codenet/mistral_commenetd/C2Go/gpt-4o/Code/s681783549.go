package main  // Declare the main package

import (  // Import necessary packages
	"fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Beginning of the main function
	var S string  // Declare a string variable 'S'

	fmt.Scan(&S)  // Read a string from standard input and store it in 'S'

	for i := 0; i < len(S)-1; i++ {  // Iterate through each character in the string 'S', stopping before the last character
		if S[i] == 'A' && S[i+1] == 'C' {  // Check if the current character is 'A' and the next character is 'C'
			fmt.Println("Yes")  // If so, print 'Yes' to the standard output
			return  // And exit the program
		}
	}

	fmt.Println("No")  // If no pair of 'AC' is found, print 'No' to the standard output
}  // End of the main function
// <END-OF-CODE>
