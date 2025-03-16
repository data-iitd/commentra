package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	vowels := "aeiouyAEIOUY"

	// Iterate over the input string in reverse order
	for i := len(input) - 2; i >= 0; i-- {
		if input[i] == ' ' || input[i] == '?' {
			continue // Continue to the next iteration
		} else {
			if contains(vowels, input[i]) {
				fmt.Println("YES") // Print "YES" if the character is a vowel
			} else {
				fmt.Println("NO") // Print "NO" if the character is not a vowel and break the loop
			}
			break // Break the loop after printing the result
		}
	}
}

func contains(s string, r byte) bool {
	for i := 0; i < len(s); i++ {
		if s[i] == r {
			return true
		}
	}
	return false
}

