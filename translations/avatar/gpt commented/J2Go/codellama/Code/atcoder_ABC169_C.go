
package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := new(Scanner)

	// Read a long integer value from the user
	a := sc.NextLong()

	// Read a string value from the user
	b := sc.Next()

	// Convert the string to a character array for processing
	bChar := []rune(b)

	// Get the length of the character array
	length := len(bChar)

	// Initialize an empty string to build the integer representation
	bStr := ""

	// Loop through each character in the character array
	for i := 0; i < length; i++ {
		// If the character is not a '.', append it to bStr
		if bChar[i] != '.' {
			bStr += string(bChar[i])
		}
	}

	// Convert the built string (bStr) to an integer
	bInt, _ := strconv.Atoi(bStr)

	// Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
	result := (a * int64(bInt)) / 100

	// Print the result to the console
	fmt.Println(result)
}

