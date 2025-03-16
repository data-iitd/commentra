
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a bufio.Reader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number from the input
	x, _ := reader.ReadString('\n')
	
	// Remove the newline character
	x = strings.Replace(x, "\n", "", -1)
	
	// Convert the string to an integer
	x, _ = strconv.ParseInt(x, 10, 64)
	
	// Initialize variables to construct the new number
	var newNumber int64 = 0
	var pow int = 0
	
	// Loop through each digit of the number from right to left
	for x > 0 {
		// Get the last digit of the number
		r := x % 10
		
		// Check if the digit is greater than 4 and if 9 - digit is less than digit
		if 9 - r < r {
			// If it's the last digit and 9 - r is 0, add the digit as is
			if x / 10 == 0 && 9 - r == 0 {
				newNumber = newNumber + r
			} else {
				// Otherwise, add 9 - digit to the new number
				newNumber = newNumber + 9 - r
			}
		} else {
			// Otherwise, add the digit to the new number
			newNumber = newNumber + r
		}
		
		// Remove the last digit from the number
		x = x / 10
		
		// Increment the place value
		pow++
	}
	
	// Print the new number
	fmt.Println(newNumber)
}

