
package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanLines)

	// Read and process the three input words
	word1 := strings.Join(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""), "")
	word2 := strings.Join(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""), "")
	word3 := strings.Join(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""), "")

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of test cases
	in.Scan()
	students := in.Text()

	// Process each test case
	for i := 0; i < len(students); i++ {
		testCase := strings.Join(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""), "")
		// Check if the test case matches any of the generated permutations
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			fmt.Println("ACC") // Print "ACC" if a match is found
		} else {
			fmt.Println("WA") // Print "WA" if no match is found
		}
	}
}

