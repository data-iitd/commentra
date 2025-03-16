
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from the user and convert it to a character array
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	chars := []rune(str)

	// Initialize variable to store the index of the decimal point
	dotIndex := 0

	// Find the index of the decimal point in the input
	for i, char := range chars {
		if char == '.' {
			dotIndex = i
			break
		}
	}

	// Check if the digit before the decimal point is '9'
	if string(chars[dotIndex-1]) == "9" {
		// If it is, print a specific message
		fmt.Println("GOTO Vasilisa.")
	} else {
		// Check if the digit after the decimal point is greater than 4
		if int(chars[dotIndex+1]) > 4 {
			// If it is, create a new string from the integer part and add 1
			intPart := string(chars[:dotIndex])
			intPartInt, _ := strconv.Atoi(intPart)
			intPartInt++
			fmt.Println(intPartInt)
		} else {
			// Print the integer part as it is
			fmt.Println(string(chars[:dotIndex]))
		}
	}
}

