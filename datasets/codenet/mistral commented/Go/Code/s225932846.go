
package main

import "fmt"

// Initialize an empty string variable named S
var S string

// Read a string input from the user using fmt.Scan function and store it in the variable S
func main() {
	fmt.Scan(&S)

	// Initialize a variable i with value 2
	var i int = 2

	// Start a for loop that runs as long as i is less than or equal to the length of the string S
	for i <= len(S) {

		// Check if the first half of the string S (from index 0 to (len(S)-i)/2) is equal to the second half of the string S (from index (len(S)-i)/2 to len(S)-i)
		if S[0:(len(S)-i)/2] == S[(len(S)-i)/2:len(S)-i] {

			// If the condition is true, print the length of the substring (len(S) - i) and break out of the loop
			fmt.Println((len(S) - i))
			break
		}

		// Increment the value of i by 2
		i += 2
	}
}

