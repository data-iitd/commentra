package main // Declare the main package

import ( // Import necessary packages
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Beginning of the main function
	var n int // Declare an integer variable 'n' to store the size of the string
	fmt.Scan(&n) // Read the size of the string from the standard input
	var s string // Declare a string variable 's' to store the string
	fmt.Scan(&s) // Read the string from the standard input
	cnt := 0 // Initialize a counter variable 'cnt' to 0

	// Beginning of the first for loop
	for i := 0; i < n; i++ { // Loop through each character in the string 's'
		cnt++ // Increment the counter variable 'cnt'
		j := i + 1 // Initialize a variable 'j' to check for the next character

		// Beginning of the inner for loop
		for j < n { // Compare the current character with the next characters in the string
			if s[i] != s[j] { // If the current character is not equal to the next character
				break // Exit the inner for loop
			}
			j++ // Increment 'j' to check the next character
		}
		i = j - 1 // If the current character is repeated, update the index 'i' to the previous index
	}

	// Output the result
	fmt.Println(cnt) // Print the value of the counter variable 'cnt' to the standard output
}

// <END-OF-CODE>
