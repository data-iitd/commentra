package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)
	
	// Reading a string input from the user
	sc.Scan()
	str := sc.Text()
	
	// Converting the string to a character slice for easier manipulation
	c := []rune(str)
	
	// Reading a long integer input from the user
	var k int64
	fmt.Scan(&k)
	
	// Getting the length of the input string
	n := len(c)
	
	// Looping through the first k characters of the character slice
	for i := 0; i < int(k); i++ {
		// Checking if the current character is '1'
		if c[i] == '1' {
			// If it's the last character in the range, print 1 and exit
			if i == int(k) - 1 {
				fmt.Println(1)
				return // Exit the program
			}
		} else {
			// If the current character is not '1', print it and exit
			fmt.Println(string(c[i]))
			return // Exit the program
		}
	}
}
