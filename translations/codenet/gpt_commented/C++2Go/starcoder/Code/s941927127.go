package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	// Read input string from the user
	reader := bufio.NewReader(os.Stdin)
	W, _ := reader.ReadString('\n')

	// Sort the characters in the string in ascending order
	sort.Strings(strings.Split(W, ""))

	// Iterate through the sorted string, checking pairs of characters
	for i := 0; i < len(W)-1; i++ {
		// Check if the current character is not equal to the next character
		if W[i]!= W[i+1] {
			// If they are not equal, print "No" and exit the program
			fmt.Println("No")
			return
		}
	}

	// If all pairs are equal, print "Yes"
	fmt.Println("Yes")
}

