package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')

	// Remove the newline character at the end of the string
	S = S[:len(S)-1]

	// Count the frequency of each character in the string S
	freq := make(map[rune]int)
	for _, char := range S {
		freq[char]++
	}

	// Convert the string S into a set of unique characters
	uniqueChars := make(map[rune]bool)
	for _, char := range S {
		uniqueChars[char] = true
	}

	// Check if the number of unique characters is not equal to 2
	if len(uniqueChars) != 2 {
		fmt.Println("No")
		return
	}

	// Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
	for char := range uniqueChars {
		if freq[char] != 2 {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("Yes")
}
