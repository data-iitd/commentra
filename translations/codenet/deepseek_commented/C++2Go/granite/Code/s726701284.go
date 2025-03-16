
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Step 1: Read a string from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	// Step 2: Iterate through each letter from 'a' to 'z'
	for i := 'a'; i <= 'z'; i++ {
		// Step 3: Count how many times the current letter appears in the input string
		count := 0
		for _, char := range s {
			if char == i {
				count++
			}
		}

		// Step 4: If the letter does not appear in the input string, print it and break out of the loop
		if count == 0 {
			fmt.Println(string(i))
			break
		}

		// Step 5: If all letters from 'a' to 'z' appear in the input string, print "None"
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}
