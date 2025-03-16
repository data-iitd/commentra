package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Read and process the three input words
	scanner.Scan()
	word1 := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))
	scanner.Scan()
	word2 := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))
	scanner.Scan()
	word3 := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of test cases
	scanner.Scan()
	students := scanner.Text()
	numStudents, _ := fmt.Sscanf(students, "%d", &students)
	if numStudents != 1 {
		return
	}

	// Process each test case
	for i := 0; i < students; i++ {
		scanner.Scan()
		testCase := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))
		// Check if the test case matches any of the generated permutations
		if testCase == perm1 || testCase == perm2 || testCase == perm3 ||
			testCase == perm4 || testCase == perm5 || testCase == perm6 {
			fmt.Println("ACC") // Print "ACC" if a match is found
		} else {
			fmt.Println("WA") // Print "WA" if no match is found
		}
	}
}

