
package main

import (
	"fmt"
	"strings"
)

// Declare empty strings s1, s2, and s3 for user input
var s1, s2, s3 string

func main() {
	// Read user input for strings s1, s2, and s3
	fmt.Scan(&s1, &s2, &s3)

	// Declare slices s1s, s2s, and s3s to store individual characters of strings s1, s2, and s3 respectively
	s1s := strings.Split(s1, "")
	s2s := strings.Split(s2, "")
	s3s := strings.Split(s3, "")

	// Print the concatenated uppercase first character of each string
	fmt.Println(strings.ToUpper(s1s[0]) + strings.ToUpper(s2s[0]) + strings.ToUpper(s3s[0]))
}

