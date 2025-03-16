package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Optimize input/output operations
	// fmt.FastIO = true

	// Declare a string to hold the input
	var str string
	// Read the input string from the user
	fmt.Scan(&str)

	// Initialize a variable to hold the sum of digits
	var sum int

	// Iterate through each character in the string
	for _, x := range str {
		// Convert character to integer and add to sum
		sum += int(x - '0')
	}

	// Check if the sum of digits is divisible by 9
	if sum%9 == 0 {
		// If divisible, print "Yes"
		fmt.Println("Yes")
	} else {
		// If not divisible, print "No"
		fmt.Println("No")
	}
}

