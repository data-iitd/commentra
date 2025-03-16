package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read a long integer from stdin
	number, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)

	// Initialize variables to store the result and the current value
	ans, value := -1, int64(0)

	// Initialize a mask variable starting from 2
	mask := 2

	// Loop until the current value is less than the input number
	for value < number {
		// Convert the current mask to a binary string and remove the leading '1'
		s := fmt.Sprintf("%b", mask)[1:]

		// Initialize a counter for zeros in the binary string
		zeros := 0

		// Count the number of '0's in the binary string
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}

		// If the number of zeros is not equal to the number of ones, skip to the next iteration
		if zeros!= len(s)-zeros {
			continue
		}

		// Replace '0's with '4's and '1's with '7's to form a new number
		s = strings.Replace(s, "0", "4", -1)
		s = strings.Replace(s, "1", "7", -1)

		// Parse the modified string as a long integer
		value, _ = strconv.ParseInt(s, 2, 64)
	}

	// Print the final value that meets the condition
	fmt.Println(value)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

