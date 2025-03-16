
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize I/O streams
func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read input string from standard input
	str, _ := reader.ReadString('\n')
	str = str[:len(str)-1] // Remove trailing newline character

	// Initialize sum variable to 0
	sum := 0

	// Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
	for _, x := range str {
		sum += int(x - '0') // Subtract '0' to convert ASCII value of digit character to its integer value
	}

	// Check if sum is divisible by 9
	if sum%9 == 0 {
		fmt.Fprintln(writer, "Yes") // Output "Yes" if sum is divisible by 9
	} else {
		fmt.Fprintln(writer, "No") // Output "No" otherwise
	}

	writer.Flush() // Flush the output buffer
}

