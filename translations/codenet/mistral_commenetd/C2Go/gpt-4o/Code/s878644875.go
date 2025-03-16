package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Declare the main function
	var s, t [4]byte // Declare two byte arrays of size 4
	fmt.Scanf("%s", &s) // Read a string of length less than or equal to 3 from the standard input and store it in array s
	fmt.Scanf("%s", &t) // Read a string of length less than or equal to 3 from the standard input and store it in array t
	hit := 0 // Initialize a counter variable hit to 0
	for i := 0; i < 3; i++ { // Start a for loop that iterates from 0 to 2 (3 times)
		if s[i] == t[i] { // If the i-th character of string s is equal to the i-th character of string t
			hit++ // Increment the counter variable hit
		}
	}
	fmt.Println(hit) // Print the value of the counter variable hit to the standard output followed by a newline character
}

// <END-OF-CODE>
