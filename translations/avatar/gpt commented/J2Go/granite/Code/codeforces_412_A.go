
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Reading two integers n and k from user input
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Reading a string a from user input
	a := readLine(reader)

	// Check if k is greater than half of n
	if k > n/2 {
		// If true, move to the right until k equals n
		for k < n {
			fmt.Println("RIGHT") // Output "RIGHT" for each step to the right
			k++ // Increment k
		}
	} else {
		// If false, move to the left until k equals 1
		for k > 1 {
			fmt.Println("LEFT") // Output "LEFT" for each step to the left
			k-- // Decrement k
		}
	}

	// If k equals 1, print the characters of the string from left to right
	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT " + string(a[i])) // Print the current character
			// If not at the last character, output "RIGHT"
			if i < len(a)-1 {
				fmt.Println("RIGHT")
			}
		}
	} else {
		// If k is not 1, print the characters of the string from right to left
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT " + string(a[i])) // Print the current character
			// If not at the first character, output "LEFT"
			if i > 0 {
				fmt.Println("LEFT")
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

