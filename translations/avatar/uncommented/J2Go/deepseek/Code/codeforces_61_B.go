package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	word1 := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))
	scanner.Scan()
	word2 := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))
	scanner.Scan()
	word3 := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2
	scanner.Scan()
	students := 0
	fmt.Sscanf(scanner.Text(), "%d", &students)
	scanner.Scan() // Consume the newline after the number of students
	for i := 0; i < students; i++ {
		scanner.Scan()
		testCase := strings.ToLower(strings.ReplaceAll(scanner.Text(), "[^a-zA-Z]", ""))
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

