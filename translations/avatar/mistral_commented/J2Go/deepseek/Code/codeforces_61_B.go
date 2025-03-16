package main

import (
	"fmt"
	"strings"
)

func main() {
	// Initializing a Scanner object to read input
	var word1, word2, word3, testCase string

	// Reading the first word from the user input
	fmt.Scanln(&word1)
	word1 = strings.ReplaceAll(strings.ToLower(word1), "[^a-zA-Z]", "")

	// Reading the second word from the user input
	fmt.Scanln(&word2)
	word2 = strings.ReplaceAll(strings.ToLower(word2), "[^a-zA-Z]", "")

	// Reading the third word from the user input
	fmt.Scanln(&word3)
	word3 = strings.ReplaceAll(strings.ToLower(word3), "[^a-zA-Z]", "")

	// Creating six permutations of the given words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Reading the number of students
	var students int
	fmt.Scanln(&students)

	// Looping through each student's test case
	for i := 0; i < students; i++ {
		// Reading a test case from the user input
		fmt.Scanln(&testCase)
		testCase = strings.ReplaceAll(strings.ToLower(testCase), "[^a-zA-Z]", "")

		// Checking if the test case matches any of the permutations
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			// Printing 'ACC' if the test case matches any of the permutations
			fmt.Println("ACC")
		} else {
			// Printing 'WA' if the test case doesn't match any of the permutations
			fmt.Println("WA")
		}
	}
}
