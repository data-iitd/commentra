package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare a string 'c' to store the input string and 'ans' to store the result
	var c, ans string
	
	// Create a new reader to read input from the user
	reader := bufio.NewReader(os.Stdin)
	
	// Read a string input from the user
	c, _ = reader.ReadString('\n')
	
	// Remove the newline character from the input string
	c = c[:len(c)-1]
	
	// Iterate through each character of the input string until the null terminator is encountered
	for i := 0; i < len(c); i++ {
		// If the current character is not 'B', append it to the 'ans' string
		if c[i] != 'B' {
			ans += string(c[i])
		} 
		// If the current character is 'B', remove the last character from 'ans' (if it exists)
		else {
			ans = ans[:len(ans)-1]
		}
	}
	
	// Print the resulting string after processing the input
	fmt.Println(ans)
}

