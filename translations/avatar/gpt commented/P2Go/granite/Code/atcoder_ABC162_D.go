
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Read the integer input N which represents the length of the string
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Read the string input S which consists of characters 'R', 'G', and 'B'
	S := bufio.NewReader(os.Stdin).ReadLine()[0:N]

	calculate(N, S)
}

func calculate(n int, s string) {
	// Convert the string into a list of characters for easier manipulation
	arr := []rune(s)

	// Count the occurrences of each color in the string
	rNum := 0
	gNum := 0
	bNum := 0
	for _, c := range arr {
		switch c {
		case 'R':
			rNum++
		case 'G':
			gNum++
		case 'B':
			bNum++
		}
	}

	// Initialize a variable to keep track of the number of valid RGB combinations found
	sum := 0

	// Loop through possible steps to form combinations of three characters
	for step := 1; step <= math.Ceil(float64(n)/2); step++ {
		// Loop through the string to form combinations based on the current step
		for i := 0; i < n-2*step; i++ {
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
	fmt.Println(rNum * gNum * bNum - sum)
}

