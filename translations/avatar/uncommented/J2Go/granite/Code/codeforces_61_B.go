
package main

import (
"bufio"
"fmt"
"os"
"regexp"
"strings"
)

func main() {
in := bufio.NewReader(os.Stdin)

word1, _ := in.ReadString('\n')
word1 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(word1, ""))

word2, _ := in.ReadString('\n')
word2 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(word2, ""))

word3, _ := in.ReadString('\n')
word3 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(word3, ""))

perm1 := word1 + word2 + word3
perm2 := word1 + word3 + word2
perm3 := word2 + word1 + word3
perm4 := word2 + word3 + word1
perm5 := word3 + word2 + word1
perm6 := word3 + word1 + word2

students, _ := in.ReadString('\n')
students = strings.TrimSpace(students)

for i := 0; i < len(students); i++ {
testCase, _ := in.ReadString('\n')
testCase = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(testCase, ""))

if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
fmt.Println("ACC")
} else {
fmt.Println("WA")
}
}
}
