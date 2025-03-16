package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	var word1, word2, word3 string
	var students int

	// Initialize a regular expression to remove non-alphabetic characters
	re := regexp.MustCompile("[^a-zA-Z]")

	// Read and process the three input words
	fmt.Scanln(&word1)
	word1 = strings.ToLower(re.ReplaceAllString(word1, ""))
	fmt.Scanln(&word2)
	word2 = strings.ToLower(re.ReplaceAllString(word2, ""))
	fmt.Scanln(&word3)
	word3 = strings.ToLower(re.ReplaceAllString(word3, ""))

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of test cases
	fmt.Scan(&students)

	// Process each test case
	for i := 0; i < students; i++ {
		var testCase string
		fmt.Scanln(&testCase)
		testCase = strings.ToLower(re.ReplaceAllString(testCase, ""))

		// Check if the test case matches any of the generated permutations
		if testCase == perm1 || testCase == perm2 || testCase == perm3 ||
			testCase == perm4 || testCase == perm5 || testCase == perm6 {
			fmt.Println("ACC") // Print "ACC" if a match is found
		} else {
			fmt.Println("WA") // Print "WA" if no match is found
		}
	}
}

// <END-OF-CODE>
