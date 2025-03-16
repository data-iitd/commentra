package main

import (
	"fmt"
)

const N = 1000

func main() {
	// 1. Define the array and variables
	var su [N]rune // Array to store the sequence of digits
	var susum int  // Variable to store the sum of the digits

	for {
		// 2. Read input and calculate sum
		var j int
		for j = 0; j < N; j++ {
			_, err := fmt.Scanf("%c", &su[j])
			if err != nil || su[j] == '\n' {
				break // Break if newline character is encountered or an error occurs
			}
			susum += int(su[j] - '0') // Convert character to integer and add to sum
		}
		if su[0] == '0' { // Break if the sequence starts with '0'
			break
		}
		// 3. Print the sum
		fmt.Println(susum) // Print the sum of the digits
		susum = 0          // Reset the sum for the next sequence
	}
	// 4. Check for termination condition
}

// <END-OF-CODE>
