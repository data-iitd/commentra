package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Step 1: Read a string from the user
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	
	// Step 2: Iterate through each letter from 'a' to 'z'
	for i := 'a'; i <= 'z'; i++ {
		// Step 3: Count how many times the current letter appears in the input string
		a := 0
		for j := 0; j < len(s); j++ {
			if i == rune(s[j]) {
				a++
			}
		}
		
		// Step 4: If the letter does not appear in the input string, print it and break out of the loop
		if a == 0 {
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
