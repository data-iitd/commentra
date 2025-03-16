package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Define a list containing all the vowels in upper and lower case
	vowels := []rune{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'}

	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Scan the input string 'a' from the user
	scanner.Scan()
	a := scanner.Text()

	// Iterate through the string 'a' from the end to the beginning
	for i := len(a) - 1; i >= 0; i-- {
		// If the current character is a space or a question mark, skip it and move on to the next character
		if a[i] == ' ' || a[i] == '?' {
			continue
		} else {
			// Check if the current character is a vowel
			isVowel := false
			for _, vowel := range vowels {
				if a[i] == vowel {
					isVowel = true
					break
				}
			}
			// If it is a vowel, print "YES" and break out of the loop
			if isVowel {
				fmt.Println("YES")
				break
			} else {
				// If it is not a vowel, print "NO" and break out of the loop
				fmt.Println("NO")
				break
			}
		}
	}
}

