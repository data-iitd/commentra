
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new Scanner object to read input from console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the input string from the console and store it in the 'a' variable
	scanner.Scan()
	a := scanner.Text()

	// Replace all occurrences of ',' in the 'a' string with a single space and store the result in the 'b' variable
	b := strings.Replace(a, ",", " ", -1)

	// Print the modified string stored in the 'b' variable to the console
	fmt.Println(b)
}

