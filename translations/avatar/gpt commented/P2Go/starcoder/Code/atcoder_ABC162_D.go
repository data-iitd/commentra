package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the integer input N which represents the length of the string
	var N int
	fmt.Scanf("%d", &N)

	// Read the string input S which consists of characters 'R', 'G', and 'B'
	var S string
	fmt.Scanf("%s", &S)

	// Convert the string into a list of characters for easier manipulation
	arr := []rune(S)

	// Count the occurrences of each color in the string
	rNum := 0
	gNum := 0
	bNum := 0
	for _, c := range arr {
		if c == 'R' {
			rNum++
		} else if c == 'G' {
			gNum++
		} else if c == 'B' {
			bNum++
		}
	}

	// Initialize a variable to keep track of the number of valid RGB combinations found
	sum := 0

	// Loop through possible steps to form combinations of three characters
	for step := 1; step <= int(math.Ceil(float64(N)/2.0))+1; step++ {
		// Loop through the string to form combinations based on the current step
		for i := 0; i < N-2*step; i++ {
			// Create a substring of three characters at the current indices
			s := string(arr[i]) + string(arr[i+step]) + string(arr[i+step*2])

			// Check if the formed substring is one of the valid RGB permutations
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				// Increment the count of valid combinations found
				sum++
			}
		}
	}

	// Calculate and print the result: total combinations minus the valid RGB combinations found
	fmt.Printf("%d\n", rNum*gNum*bNum-sum)
}

