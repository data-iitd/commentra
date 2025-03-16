package main // Define the main package

import (
	"fmt" // Import the fmt package for printing and scanning
)

func main() { // Define the main function
	var s, t [4]byte // Declare byte arrays to store input strings
	fmt.Scanf("%s", &s) // Read the first string from the user and store it in s
	fmt.Scanf("%s", &t) // Read the second string from the user and store it in t
	hit := 0 // Initialize a counter for hits
	for i := 0; i < 3; i++ { // Compare characters in the strings
		if s[i] == t[i] { // Increment the hit counter if characters match
			hit++
		}
	}
	fmt.Println(hit) // Print the number of matching characters
}

// <END-OF-CODE>
