package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read three words from stdin, remove non-alphabetic characters, and convert to lowercase
	word1 := strings.ToLower(strings.Join(strings.Fields(readLine(reader)), ""))
	word2 := strings.ToLower(strings.Join(strings.Fields(readLine(reader)), ""))
	word3 := strings.ToLower(strings.Join(strings.Fields(readLine(reader)), ""))

	// Generate all possible permutations of the three words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Read the number of students (test cases)
	students, _ := strconv.Atoi(readLine(reader))

	// Loop through each student's test case
	for i := 0; i < students; i++ {
		// Read the test case input, remove non-alphabetic characters, and convert to lowercase
		testCase := strings.ToLower(strings.Join(strings.Fields(readLine(reader)), ""))

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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

