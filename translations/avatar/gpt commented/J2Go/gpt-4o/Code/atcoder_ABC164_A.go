package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	// Creating a slice to store the input strings
	var scList []string

	// Continuously read input lines until EOF
	for {
		var input string
		_, err := fmt.Scanln(&input)
		if err != nil {
			break // Break the loop if an error occurs (e.g., no more input)
		}
		scList = append(scList, input)
	}

	// Splitting the first line of input into a slice of strings
	numlist := strings.Split(scList[0], " ")

	// Parsing the first number as the count of sheep
	Sheep := 0
	fmt.Sscanf(numlist[0], "%d", &Sheep)

	// Parsing the second number as the count of wolves
	Wolve := 0
	fmt.Sscanf(numlist[1], "%d", &Wolve)

	// Checking if the number of wolves is greater than or equal to the number of sheep
	if Wolve >= Sheep {
		// If wolves are greater than or equal to sheep, it's unsafe
		fmt.Println("unsafe")
	} else {
		// If wolves are fewer than sheep, it's safe
		fmt.Println("safe")
	}
}

// <END-OF-CODE>
