package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t) // Read two strings from standard input

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

// <END-OF-CODE>
