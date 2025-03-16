package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Scan the input string from the user
	scanner.Scan()
	S := scanner.Text()

	// Create a map to count the frequency of each character in the string
	c := make(map[rune]int)

	// Iterate over each character in the string and count its occurrences
	for _, char := range S {
		c[char]++
	}

	// Create a set to store unique characters from the input string
	Sa := make(map[rune]bool)

	// Iterate over each character in the string and add it to the set
	for _, char := range S {
		Sa[char] = true
	}

	// Check if the number of unique characters is not equal to 2
	if len(Sa) != 2 {
		// If there are not exactly 2 unique characters, print "No" and exit
		fmt.Println("No")
		return
	}

	// Iterate over each unique character in the set
	for char := range Sa {
		// Check if the count of the current character is not equal to 2
		if c[char] != 2 {
			// If any character does not appear exactly twice, print "No" and exit
			fmt.Println("No")
			return
		}
	}

	// If both conditions are satisfied, print "Yes"
	fmt.Println("Yes")
}

