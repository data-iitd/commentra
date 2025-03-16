package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read a long integer from stdin
	a, _ := strconv.ParseInt(readLine(reader), 10, 64)

	// Read a string from stdin
	b := readLine(reader)

	// Convert the string to a character array
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
	bInt, _ := strconv.ParseInt(bStr, 10, 64)

	// Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
	result := (a * bInt) / 100

	// Print the result to stdout
	fmt.Println(result)
}

// readLine reads a string from stdin
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

