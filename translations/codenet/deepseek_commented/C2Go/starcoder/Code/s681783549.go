<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	// Declare an integer variable to be used as a loop counter
	var i int

	// Declare a character array to store the input string
	var S [6]byte

	// Read a string input from the user and store it in S
	fmt.Scanf("%s", &S)

	// Loop through each character in the string S
	for i = 0; S[i]!= 0; i++ {
		// Check if the current character is 'A' and the next character is 'C'
		if S[i] == 'A' && S[i+1] == 'C' {
			// If the condition is met, print "Yes" and exit the program
			fmt.Println("Yes")
			return
		}
	}

	// If the condition is not met after the loop completes, print "No" and exit the program
	fmt.Println("No")
	return
}

