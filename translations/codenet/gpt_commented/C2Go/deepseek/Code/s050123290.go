package main

import (
	"fmt"
)

func main() {
	const N = 1000  // Define a constant N to represent the maximum size of the input array

	var su [N]rune  // Declare a rune array to store the input
	var susum int   // Initialize a variable to hold the sum of the digits

	// Infinite loop to continuously read input until a specific condition is met
	for {
		// Loop to read characters into the array until a newline is encountered or the limit is reached
		for j := 0; j < N; j++ {
			_, err := fmt.Scanf("%c", &su[j])  // Read a character from standard input
			if err != nil {
				return  // Exit the loop if an error occurs
			}
			if su[j] == '\n' {
				break  // Break the loop if a newline character is encountered
			}
			susum += int(su[j] - '0')  // Convert the character to an integer and add it to the sum
		}

		// Check if the first character is '0', which indicates the end of input
		if su[0] == '0' {
			break  // Exit the loop if the first character is '0'
		}

		fmt.Println(susum)  // Print the sum of the digits read
		susum = 0  // Reset the sum for the next input
	}
}

