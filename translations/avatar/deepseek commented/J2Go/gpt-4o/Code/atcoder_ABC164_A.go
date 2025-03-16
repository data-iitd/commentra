package main

import (
	"fmt"
	"log"
	"strconv"
	"strings"
)

func main() {
	var input string
	var scList []string

	// Continuously read input lines from the user
	for {
		_, err := fmt.Scanln(&input)
		if err != nil {
			break // Exit the loop if an error occurs
		}
		scList = append(scList, input) // Add the input line to the slice
	}

	// Get the first line of input and split it into an array of strings
	numlist := strings.Split(scList[0], " ")

	// Parse the first element to get the number of sheep
	Sheep, err := strconv.Atoi(numlist[0])
	if err != nil {
		log.Fatal(err)
	}

	// Parse the second element to get the number of wolves
	Wolve, err := strconv.Atoi(numlist[1])
	if err != nil {
		log.Fatal(err)
	}

	// Check if the number of wolves is greater than or equal to the number of sheep
	if Wolve >= Sheep {
		fmt.Println("unsafe") // Print "unsafe" if the condition is true
	} else {
		fmt.Println("safe") // Print "safe" otherwise
	}
}

// <END-OF-CODE>
