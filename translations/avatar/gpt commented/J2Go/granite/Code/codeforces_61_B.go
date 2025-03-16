
package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

func main() {
	// Create a scanner object to read input from the console
	in := bufio.NewReader(os.Stdin)

	// Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
	word1, _ := in.ReadString('\n')
	word1 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(word1, ""))
	word2, _ := in.ReadString('\n')
	word2 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(word2, ""))
	word3, _ := in.ReadString('\n')
	word3 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(word3, ""))

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of students (test cases)
	students, _ := in.ReadString('\n')
	students = strings.TrimSpace(students)
	studentsInt, _ := strconv.Atoi(students)

	// Loop through each student's test case
	for i := 0; i < studentsInt; i++ {
		// Read the test case input, remove non-alphabetic characters, and convert to lowercase
		testCase, _ := in.ReadString('\n')
		testCase = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(testCase, ""))

		// Check if the test case matches any of the generated permutations
		if testCase == perm1 || testCase == perm2 ||
			testCase == perm3 || testCase == perm4 ||
			testCase == perm5 || testCase == perm6 {
			// If it matches, print "ACC" (Accepted)
			fmt.Println("ACC")
		} else {
			// If it doesn't match, print "WA" (Wrong Answer)
			fmt.Println("WA")
		}
	}
}
