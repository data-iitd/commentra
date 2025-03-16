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

	// Reading input lines from the console
	for {
		_, err := fmt.Scanln(&input)
		if err != nil {
			break // Exiting the loop if an error occurs during input reading
		}
		scList = append(scList, input) // Adding the input line to the slice
	}

	// Extracting the first line of the input (which contains the number of sheep and wolves)
	numlist := strings.Split(scList[0], " ")

	// Parsing the first two elements of the numlist slice as integers
	Sheep, err := strconv.Atoi(numlist[0])
	if err != nil {
		log.Fatal(err)
	}
	Wolve, err := strconv.Atoi(numlist[1])
	if err != nil {
		log.Fatal(err)
	}

	// Checking if the number of wolves is greater than or equal to the number of sheep
	if Wolve >= Sheep {
		fmt.Println("unsafe") // Printing the message "unsafe" to the console
	} else {
		fmt.Println("safe") // Printing the message "safe" to the console
	}
}

// <END-OF-CODE>
