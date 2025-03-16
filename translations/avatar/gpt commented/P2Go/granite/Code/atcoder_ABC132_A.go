
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Take input string from the user
	S := readString()

	// Create a map to count the frequency of each character in the string
	m := make(map[rune]int)
	for _, r := range S {
		m[r]++
	}

	// Create a set to store unique characters from the input string
	sa := make(map[rune]bool)
	for _, r := range S {
		sa[r] = true
	}

	// Check if the number of unique characters is not equal to 2
	if len(sa)!= 2 {
		// If there are not exactly 2 unique characters, print "No" and exit
		fmt.Println("No")
		return
	}

	// Iterate over each unique character in the set
	for r := range sa {
		// Check if the count of the current character is not equal to 2
		if m[r]!= 2 {
			// If any character does not appear exactly twice, print "No" and exit
			fmt.Println("No")
			return
		}
	}

	// If both conditions are satisfied, print "Yes"
	fmt.Println("Yes")
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

