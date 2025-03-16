
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read a string from standard input and store it in the'mes' variable
	scanner.Scan()
	mes := scanner.Text()

	// Print the first character of the string, the length of the string minus 2, and the last character of the string
	fmt.Printf("%c%d%c\n", mes[0], len(mes)-2, mes[len(mes)-1])
}

// 