
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// 1. Define the array and variables
	su := make([]byte, 1000) // Array to store the sequence of digits
	susum := 0               // Variable to store the sum of the digits
	j := 0                   // Index to iterate through the array

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// 2. Read input and calculate sum
		su = scanner.Bytes()
		for j = 0; j < len(su); j++ {
			if su[j] == '\n' {
				break
			}
			susum += int(su[j] - '0') // Convert character to integer and add to sum
		}
		if su[0] == '0' {
			break
		}
		// 3. Print the sum
		fmt.Println(susum) // Print the sum of the digits
		susum = 0           // Reset the sum for the next sequence
	}
	// 4. Check for termination condition
}

// 