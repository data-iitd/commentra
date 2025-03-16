
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Read a line from input using the bufio package
	input_string, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	// Replace all commas with spaces in the input string
	modified_string := strings.Replace(input_string, ",", " ", -1)

	// Print the modified string to the console
	fmt.Println(modified_string)
}

