package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	// Creating a regular expression to remove non-alphabetic characters
	re := regexp.MustCompile("[^a-zA-Z]")

	// Reading the first word from the user input
	var word1 string
	fmt.Scanln(&word1)
	word1 = strings.ToLower(re.ReplaceAllString(word1, ""))

	// Reading the second word from the user input
	var word2 string
	fmt.Scanln(&word2)
	word2 = strings.ToLower(re.ReplaceAllString(word2, ""))

	// Reading the third word from the user input
	var word3 string
	fmt.Scanln(&word3)
	word3 = strings.ToLower(re.ReplaceAllString(word3, ""))

	// Creating six permutations of the given words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Reading the number of students
	var students int
	fmt.Scan(&students)

	// Looping through each student's test case
	for i := 0; i < students; i++ {
		// Reading a test case from the user input
		var testCase string
		fmt.Scanln(&testCase)
		testCase = strings.ToLower(re.ReplaceAllString(testCase, ""))

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

// <END-OF-CODE>
