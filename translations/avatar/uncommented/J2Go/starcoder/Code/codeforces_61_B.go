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
	word1 := regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Scan().Text(), "")
	word2 := regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Scan().Text(), "")
	word3 := regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Scan().Text(), "")
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2
	students := in.Scan()
	for i := 0; i < students.Int(); i++ {
		testCase := regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Scan().Text(), "")
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

