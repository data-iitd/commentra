package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input) // Read an input line (not used in further calculations)

	var a string
	fmt.Scanln(&a) // Read a string input from the user

	// Check if the string contains any '1's
	// If there are no '1's, print 0
	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
		return
	}

	// Split the input string by '1's
	segments := strings.Split(a, "1")
	product := 1

	for _, segment := range segments {
		// Count '0's in each segment and add 1 to each count
		countZeros := strings.Count(segment, "0") + 1
		product *= countZeros
	}

	fmt.Println(product) // Print the product of counts of '0's between '1's
}

// <END-OF-CODE>
