// 2018-07-29T20:36:21+0800
package main

import (
	"fmt" // Import the fmt package for formatted I/O
	"strings" // Import the strings package for string manipulation
)

// Define a variable `s` of type `string` to store the user input.
var s string

// Read a string input from the standard input and store it in the variable `s`.
func main() {
	fmt.Print("Enter a string: ") // Print a prompt message to the standard output.
	fmt.Scanf("%s", &s) // Read a string input from the standard input and store it in the variable `s`.

	// Replace all occurrences of the string "2017" in the string `s` with the string "2018".
	s = strings.Replace(s, "2017", "2018", -1)

	// Print the modified string to the standard output.
	fmt.Println("Modified string:", s)
}

// End of code.
