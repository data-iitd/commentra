
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s, t := readTwoStrings() // Read two strings from standard input

	// Concatenate s with itself to double its length
	s += s

	// Check if t is a substring of the doubled s
	// If found, find returns the position; otherwise, it returns string::npos
	// Convert the result to a boolean for easy printing
	if strings.Contains(s, t) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func readTwoStrings() (string, string) {
	scanner := bufio.NewScanner(os.Stdin)
	var s, t string
	scanner.Scan()
	s = scanner.Text()
	scanner.Scan()
	t = scanner.Text()
	return s, t
}

