package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input from the console
	var input string
	fmt.Scanln(&input)

	// Split the input string into an array of strings
	str := strings.Split(input, " ")

	// Parse the first string as an integer representing the initial health
	h, _ := strconv.Atoi(str[0])

	// Parse the second string as an integer representing the damage dealt per attack
	a, _ := strconv.Atoi(str[1])

	// Initialize a counter to keep track of the number of attacks
	num := 0

	// Loop until the health is greater than zero
	for h > 0 {
		// Decrease health by the amount of damage dealt
		h -= a

		// Increment the attack counter
		num++
	}

	// Output the total number of attacks required to reduce health to zero or below
	fmt.Println(num)
}

// <END-OF-CODE>
