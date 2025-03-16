
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize Scanner for input operations
	scanner := bufio.NewScanner(os.Stdin)

	// Read and process the three input words
	word1 := scanner.Text()
	word2 := scanner.Text()
	word3 := scanner.Text()

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of test cases
	students := scanner.Text()

	// Process each test case
	for i := 0; i < students; i++ {
		testCase := scanner.Text()
		// Check if the test case matches any of the generated permutations
		if strings.EqualFold(testCase, perm1) || strings.EqualFold(testCase, perm2) || strings.EqualFold(testCase, perm3) || strings.EqualFold(testCase, perm4) || strings.EqualFold(testCase, perm5) || strings.EqualFold(testCase, perm6) {
			fmt.Println("ACC") // Print "ACC" if a match is found
		} else {
			fmt.Println("WA") // Print "WA" if no match is found
		}
	}
}

