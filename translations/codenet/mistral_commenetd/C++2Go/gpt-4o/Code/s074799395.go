package main // Declare the main package

import (
	"fmt" // Import the fmt package for input and output operations
)

func main() { // Start of the main function
	var B rune // Declare a rune variable named B to store the input character
	var OUT rune // Declare a rune variable named OUT to store the output character

	fmt.Scanf("%c", &B) // Read a character from the standard input and store it in variable B

	// Logic block to determine the output character based on the input character
	if B == 'A' { // If the input character is 'A'
		OUT = 'T' // Set the output character to 'T'
	} else if B == 'T' { // If the input character is 'T'
		OUT = 'A' // Set the output character to 'A'
	} else if B == 'C' { // If the input character is 'C'
		OUT = 'G' // Set the output character to 'G'
	} else { // If the input character is neither 'A', 'T', nor 'C'
		OUT = 'C' // Set the output character to 'C'
	}

	fmt.Println(string(OUT)) // Output the result character to the standard output
}

// <END-OF-CODE>
