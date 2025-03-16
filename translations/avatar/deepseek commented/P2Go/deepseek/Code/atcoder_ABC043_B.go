package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]  // Remove the newline character

	myStr := ""  // Initialize an empty string to build the result

	// Iterate over each character in the input string `s`
	for _, c := range s {
		if c == '0' || c == '1' {  // Check if the character is '0' or '1'
			myStr += string(c)  // Append the character to `myStr`
		} else if c == 'B' && len(myStr) != 0 {  // Check if the character is 'B' and `myStr` is not empty
			myStr = myStr[:len(myStr)-1]  // Remove the last character from `myStr`
		}
	}

	fmt.Println(myStr)  // Print the content of `myStr`
}
