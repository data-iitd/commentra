
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
	word1 := scanner.Text()
	word1 = strings.Replace(word1, "[^a-zA-Z]", "", -1)
	word1 = strings.ToLower(word1)

	word2 := scanner.Text()
	word2 = strings.Replace(word2, "[^a-zA-Z]", "", -1)
	word2 = strings.ToLower(word2)

	word3 := scanner.Text()
	word3 = strings.Replace(word3, "[^a-zA-Z]", "", -1)
	word3 = strings.ToLower(word3)

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of students (test cases)
	students := scanner.Text()
	students = strings.Replace(students, "[^0-9]", "", -1)
	students = strings.ToLower(students)

	// Loop through each student's test case
	for i := 0; i < len(students); i++ {
		// Read the test case input, remove non-alphabetic characters, and convert to lowercase
		testCase := scanner.Text()
		testCase = strings.Replace(testCase, "[^a-zA-Z]", "", -1)
		testCase = strings.ToLower(testCase)

		// Check if the test case matches any of the generated permutations
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			// If it matches, print "ACC" (Accepted)
			fmt.Println("ACC")
		} else {
			// If it doesn't match, print "WA" (Wrong Answer)
			fmt.Println("WA")
		}
	}
}

