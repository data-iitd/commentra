package main

import (
	"fmt"
	"log"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input from the console
	var input string
	_, err := fmt.Scanln(&input)
	if err != nil {
		log.Fatal(err)
	}

	// Split the input string into an array of strings
	x := strings.Fields(input)

	// Parse the first and second elements of the array as integers
	a, err := strconv.Atoi(x[0])
	if err != nil {
		log.Fatal(err)
	}
	b, err := strconv.Atoi(x[1])
	if err != nil {
		log.Fatal(err)
	}

	// Calculate the value of c based on the formula: c = a - b * 2
	c := a - b*2

	// If c is negative, set it to 0
	if c < 0 {
		c = 0
	}

	// Output the final value of c
	fmt.Println(c)
}

// <END-OF-CODE>
