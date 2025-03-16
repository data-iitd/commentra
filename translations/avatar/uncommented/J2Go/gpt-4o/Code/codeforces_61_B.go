package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	var word1, word2, word3 string
	var students int

	// Read input and clean it
	word1 = cleanInput()
	word2 = cleanInput()
	word3 = cleanInput()

	// Generate permutations
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read number of students
	fmt.Scan(&students)
	// Consume the newline character after the integer input
	fmt.Scanln()

	for i := 0; i < students; i++ {
		testCase := cleanInput()
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

// cleanInput reads a line, removes non-alphabetic characters, and converts to lowercase
func cleanInput() string {
	var input string
	fmt.Scanln(&input)
	re := regexp.MustCompile("[^a-zA-Z]")
	cleaned := re.ReplaceAllString(input, "")
	return strings.ToLower(cleaned)
}
