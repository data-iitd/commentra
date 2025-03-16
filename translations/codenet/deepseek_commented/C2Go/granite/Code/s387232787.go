
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Array to store the count of each letter (a-z)
	c := make([]int, 26)

	// Read input strings until there are no more inputs
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Pointer to traverse the string
		str := scanner.Text()
		p := strings.NewReader(str)

		// Traverse each character in the string
		for {
			ch, _, err := p.ReadRune()
			if err!= nil {
				break
			}

			// Check if the character is a lowercase letter
			if 'a' <= ch && ch <= 'z' {
				// Increment the count for the corresponding letter
				c[ch-'a']++
			}
			// Check if the character is an uppercase letter
			else if 'A' <= ch && ch <= 'Z' {
				// Increment the count for the corresponding letter
				c[ch-'A']++
			}
		}
	}

	// Print the counts for each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

