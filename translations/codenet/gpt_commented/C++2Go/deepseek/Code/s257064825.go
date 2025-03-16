package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new reader to read input from the standard input
	reader := bufio.NewReader(os.Stdin)
	// Read the input string from the user
	str, _ := reader.ReadString('\n')
	// Remove the trailing newline character from the input string
	str = strings.TrimSpace(str)
	
	// Initialize a variable to hold the sum of digits
	var sum int
	
	// Iterate through each character in the string
	for _, x := range str {
		// Convert character to integer and add to sum
		digit, _ := strconv.Atoi(string(x))
		sum += digit
	}
	
	// Check if the sum of digits is divisible by 9
	if sum % 9 == 0 {
		// If divisible, print "Yes"
		fmt.Println("Yes")
	} else {
		// If not divisible, print "No"
		fmt.Println("No")
	}
}

