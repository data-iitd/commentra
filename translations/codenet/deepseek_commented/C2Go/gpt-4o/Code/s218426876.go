package main

import (
	"fmt"
)

func main() {
	var sum int
	var x string

	for {
		fmt.Scan(&x) // Read the first string from the input
		if x[0] == '0' { // Check if the first character is '0'
			break // Exit the loop if it is
		}

		sum = 0 // Reset the sum for the new string
		for i := 0; i < len(x); i++ { // Loop through each character in the string
			sum += int(x[i] - '0') // Convert the character to its corresponding digit and add it to the sum
		}
		fmt.Println(sum) // Print the sum of the digits
	}
}
