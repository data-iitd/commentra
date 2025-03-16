package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the input from standard input
	var a string
	fmt.Scanln(&a)

	// Check if the string contains any '1' character
	if strings.Count(a, "1") == 0 {
		// If it doesn't, print 0 and exit the program
		fmt.Println(0)
		return
	}

	// Split the string by '1' and calculate the product of the number of zeros in each segment
	segments := strings.Split(strings.Trim(a, "0 "), "1")
	productOfZeros := 1

	for _, segment := range segments {
		// Count the number of zeros in the segment and add 1
		zeroCount := len(segment)
		productOfZeros *= (zeroCount + 1)
	}

	// Finally, print the result
	fmt.Println(productOfZeros)
}

// <END-OF-CODE>
