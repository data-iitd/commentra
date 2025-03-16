package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	str, _ := reader.ReadString('\n')
	str = str[:len(str)-1] // Remove newline character
	c := []rune(str)       // Convert string to rune slice

	var k int64
	fmt.Print("Enter the value of k: ")
	fmt.Scan(&k)
	n := len(c) // Initialize the length of the string

	for i := 0; i < int(k); i++ { // Loop through the character array k times
		if c[i] == '1' { // Check if the character at the current index is '1'
			if i == int(k)-1 { // Check if the current index is the last index
				fmt.Println(1) // Print '1' and return
				return
			}
		} else { // If it is not '1'
			fmt.Println(string(c[i])) // Print the character and return
			return
		}
	}
}
