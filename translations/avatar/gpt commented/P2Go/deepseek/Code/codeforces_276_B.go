package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove the newline character

	// Initialize a flag variable and a dictionary to count occurrences of each character
	var x bool = true
	dt := make(map[rune]int)

	// Count the occurrences of each character in the input list
	for _, char := range input {
		if _, exists := dt[char]; exists {
			dt[char] += 1 // Increment the count if the character is already in the dictionary
		} else {
			dt[char] = 1 // Initialize the count to 1 if the character is not in the dictionary
		}
	}

	// Initialize a counter for odd occurrences and a flag variable
	var cnt int = 0
	var x2 bool = true

	// Check the counts of each character to determine the number of odd occurrences
	for _, value := range dt {
		if value%2 != 0 && cnt < 1 {
			cnt += 1 // Count the first odd occurrence
		} else if value%2 != 0 && cnt >= 1 {
			x2 = false // More than one odd occurrence found, set flag to False
			break
		}
	}

	// Determine the output based on the number of odd occurrences and the length of the input
	if x2 {
		fmt.Println("First") // If there are no more than one odd occurrences, print "First"
	} else if !x2 && len(input)%2 == 0 {
		fmt.Println("Second") // If there are more than one odd occurrences and the length is even, print "Second"
	} else if !x2 && len(input)%2 != 0 {
		fmt.Println("First") // If there are more than one odd occurrences and the length is odd, print "First"
	}
}

