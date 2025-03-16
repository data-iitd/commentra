package main

import (
	"fmt"
)

func main() {
	const N = 1000 // Define a constant N with the value 1000

	for { // Start an infinite loop
		var su [N]rune // Declare a rune array 'su' of size N
		var susum int = 0 // Initialize an integer variable 'susum' to zero
		var j int = 0 // Initialize an integer variable 'j' to zero

		for { // Start an infinite loop
			var input rune
			fmt.Scanf("%c", &input) // Read a character from the standard input and store it in the variable 'input'
			if input == '\n' {
				break // If the character read is a newline character, break out of the loop
			}
			su[j] = input // Store the character in the array 'su' at the current index
			susum += int(input - '0') // Add the ASCII value of the character (after subtracting '0') to the variable 'susum'
			j++ // Increment the index 'j'
		}

		if su[0] == '0' {
			break // If the first character of the array 'su' is '0', break out of the loop
		}
		fmt.Println(susum) // Print the sum of the digits read from the standard input
		susum = 0 // Reset the variable 'susum' to zero for the next iteration
	}
}

