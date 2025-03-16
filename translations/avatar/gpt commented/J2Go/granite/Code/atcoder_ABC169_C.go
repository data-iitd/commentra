
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read a long integer value from the user
	scanner.Scan()
	a, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	// Read a string value from the user
	scanner.Scan()
	b := scanner.Text()

	// Convert the string to a character array for processing
	bChar := []rune(b)

	// Get the length of the character array
	length := len(bChar)

	// Initialize an empty string to build the integer representation
	bStr := ""

	// Loop through each character in the character array
	for i := 0; i < length; i++ {
		// If the character is not a '.', append it to bStr
		if bChar[i]!= '.' {
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

