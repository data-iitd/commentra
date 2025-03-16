package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')

	// Remove the newline character from the end of the strings
	s = strings.TrimSuffix(s, "\n")
	t = strings.TrimSuffix(t, "\n")

	// Concatenate s with itself to double its length
	s += s

	// Check if t is a substring of the doubled s
	// If found, strings.Contains returns true; otherwise, it returns false
	if strings.Contains(s, t) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

