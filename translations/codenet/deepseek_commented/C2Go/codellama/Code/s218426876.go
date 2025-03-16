package main

import (
	"fmt"
)

func main() {
	var i, sum int = 0, 0
	var flag int = 0
	var x [1002]byte // Declare a character array to store the input string
	fmt.Scanf("%s", &x) // Read the first string from the input
	for {
		for i = 0; i < 1002; i++ { // Loop through each character in the string
			if x[i] == 0 { // Check if the current character is the null terminator
				fmt.Printf("%d\n", sum) // Print the sum of the digits and exit the loop
				break
			} else {
				sum += int(x[i]) - 0x30 // Convert the character to its corresponding digit and add it to the sum
			}
		}
		sum = 0 // Reset the sum for the next string
		fmt.Scanf("%s", &x) // Read the next string from the input
		if x[0] == 0x30 {
			break
		}
	}
}

