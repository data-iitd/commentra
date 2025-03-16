package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var str [30]rune

	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read a line of text from the standard input and store it in str array
	fmt.Print("Enter a string: ")
	text, _ := reader.ReadString('\n')
	for i := 0; i < len(text); i++ {
		str[i] = rune(text[i])
	}

	// Assign a space character to the 5th index and 13th index of the string str
	str[5] = ' '
	str[13] = ' '

	// Print the modified string using fmt.Println() function
	fmt.Printf("%s\n", string(str[:]))
}

