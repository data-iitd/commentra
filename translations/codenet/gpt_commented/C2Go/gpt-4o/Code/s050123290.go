package main

import (
	"fmt"
)

const N = 1000 // Define a constant N to represent the maximum size of the input array

func main() {
	var su [N]rune // Declare a rune array to store the input
	var susum int   // Initialize a variable to hold the sum of the digits

	for {
		j := 0 // Initialize a counter variable for the loop

		// Loop to read characters into the array until a newline is encountered or the limit is reached
		for j < N {
			var ch rune
			_, err := fmt.Scanf("%c", &ch) // Read a character from standard input
			if err != nil || ch == '\n' {  // Break the loop if an error occurs or a newline character is encountered
				break
			}
			su[j] = ch
			susum += int(ch - '0') // Convert the character to an integer and add it to the sum
			j++
		}

		// Check if the first character is '0', which indicates the end of input
		if su[0] == '0' {
			break // Exit the loop if the first character is '0'
		}

		fmt.Println(susum) // Print the sum of the digits read
		susum = 0          // Reset the sum for the next input
	}
}
