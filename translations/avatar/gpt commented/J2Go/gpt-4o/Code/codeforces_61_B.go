package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	// Create a scanner to read input from the console
	var word1, word2, word3 string
	fmt.Scanln(&word1)
	fmt.Scanln(&word2)
	fmt.Scanln(&word3)

	// Remove non-alphabetic characters and convert to lowercase
	word1 = cleanString(word1)
	word2 = cleanString(word2)
	word3 = cleanString(word3)

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of students (test cases)
	var students int
	fmt.Scan(&students)

	// Loop through each student's test case
	for i := 0; i < students; i++ {
		var testCase string
		fmt.Scanln(&testCase)

		// Clean the test case input
		testCase = cleanString(testCase)

		// Check if the test case matches any of the generated permutations
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || 
			testCase == perm4 || testCase == perm5 || testCase == perm6 {
			// If it matches, print "ACC" (Accepted)
			fmt.Println("ACC")
		} else {
			// If it doesn't match, print "WA" (Wrong Answer)
			fmt.Println("WA")
		}
	}
}

// cleanString removes non-alphabetic characters and converts to lowercase
func cleanString(s string) string {
	re := regexp.MustCompile("[^a-zA-Z]")
	return strings.ToLower(re.ReplaceAllString(s, ""))
}
