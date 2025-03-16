package main

import (
	"fmt"
)

const N = 1000 // Define a constant N with the value 1000

func main() {
	var su [N]rune // Declare a rune array 'su' of size N
	var susum int   // Initialize an integer variable 'susum' to zero

	for {
		var j int // Initialize an integer variable 'j' to zero
		for j = 0; j < N; j++ { // Iterate through each index of the array 'su'
			_, err := fmt.Scanf("%c", &su[j]) // Read a character from the standard input and store it in the array 'su' at the current index
			if err != nil || su[j] == '\n' { // If there's an error or the character read is a newline character, break out of the loop
				break
			}
			susum += int(su[j] - '0') // Add the integer value of the character (after subtracting '0') to the variable 'susum'
		}
		if su[0] == '0' { // If the first character of the array 'su' is '0', break out of the loop
			break
		}
		fmt.Println(susum) // Print the sum of the digits read from the standard input
		susum = 0 // Reset the variable 'susum' to zero for the next iteration
	}
}
