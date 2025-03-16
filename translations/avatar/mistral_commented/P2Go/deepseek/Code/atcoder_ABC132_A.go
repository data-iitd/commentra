package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Take a string as input from the user
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')

	// Import the Counter function from the collections module to count the frequency of each character in the string
	// In Go, we can use a map to count the frequency of each character

	// Create a map c to count the frequency of each character in the string S
	c := make(map[rune]int)

	// Iterate through each character in the string S
	for _, char := range S {
		c[char]++
	}

	// Create a set Sa from the list of characters in the string S
	Sa := make(map[rune]bool)
	for char := range c {
		Sa[char] = true
	}

	// Check if the length of the set Sa is equal to 2
	if len(Sa) != 2 {
		// If not, print "No" and exit the program
		fmt.Println("No")
		return
	}

	// Iterate through each character i in the set Sa
	for i := range Sa {
		// For each character i, check if its frequency in the string S is equal to 2 using the map c
		if c[i] != 2 {
			// If the frequency of any character is not equal to 2, print "No" and exit the program
			fmt.Println("No")
			return
		}
	}

	// If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
	fmt.Println("Yes")
}

