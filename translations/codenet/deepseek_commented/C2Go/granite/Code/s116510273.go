
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
	mes, _ := reader.ReadString('\n') // Read a string input from the user and store it in'mes'

	// Remove the first and last character from the string
	mes = strings.Trim(mes, "\n")

	// Calculate the length of the string
	length := len(mes)

	// Print the first character, the calculated length, and the last character of the string
	fmt.Printf("%c%d%c\n", mes[0], length, mes[length-1])
}

