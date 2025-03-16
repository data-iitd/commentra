
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	userInput, _ := reader.ReadString('\n')

	// Replace all commas in the input string with spaces
	modifiedInput := strings.Replace(userInput, ",", " ", -1)

	fmt.Println(modifiedInput)
}

