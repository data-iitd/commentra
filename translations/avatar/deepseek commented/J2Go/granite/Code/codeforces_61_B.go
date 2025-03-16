

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Initialize Scanner for input operations
    in := bufio.NewReader(os.Stdin)

    // Read and process the three input words
    word1, _ := in.ReadString('\n')
    word1 = strings.ToLower(strings.ReplaceAll(word1, "\n", ""))
    word2, _ := in.ReadString('\n')
    word2 = strings.ToLower(strings.ReplaceAll(word2, "\n", ""))
    word3, _ := in.ReadString('\n')
    word3 = strings.ToLower(strings.ReplaceAll(word3, "\n", ""))

    // Generate all possible permutations of the three words
    perm1 := word1 + word2 + word3
    perm2 := word1 + word3 + word2
    perm3 := word2 + word1 + word3
    perm4 := word2 + word3 + word1
    perm5 := word3 + word2 + word1
    perm6 := word3 + word1 + word2

    // Read the number of test cases
    students, _ := in.ReadString('\n')
    students = strings.ToLower(strings.ReplaceAll(students, "\n", ""))

    // Process each test case
    for i := 0; i < len(students); i++ {
        testCase, _ := in.ReadString('\n')
        testCase = strings.ToLower(strings.ReplaceAll(testCase, "\n", ""))

        // Check if the test case matches any of the generated permutations
        if testCase == perm1 || testCase == perm2 || testCase == perm3 ||
            testCase == perm4 || testCase == perm5 || testCase == perm6 {
            fmt.Println("ACC") // Print "ACC" if a match is found
        } else {
            fmt.Println("WA") // Print "WA" if no match is found
        }
    }
}

