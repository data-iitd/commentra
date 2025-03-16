
package main

import (
    "bufio"
    "fmt"
    "os"
    "regexp"
    "strings"
)

func main() {
    // Initializing a Scanner object to read input
    in := bufio.NewReader(os.Stdin)

    // Reading the first word from the user input
    word1, _ := in.ReadString('\n')
    // This block of code reads a line from the user input and stores it in the 'word1' variable.
    // The '\n' character is used as the delimiter to read the entire line.

    // Reading the second word from the user input
    word2, _ := in.ReadString('\n')
    // This block of code reads a line from the user input and stores it in the 'word2' variable.
    // The '\n' character is used as the delimiter to read the entire line.

    // Reading the third word from the user input
    word3, _ := in.ReadString('\n')
    // This block of code reads a line from the user input and stores it in the 'word3' variable.
    // The '\n' character is used as the delimiter to read the entire line.

    // Creating six permutations of the given words
    perm1 := word1 + word2 + word3
    perm2 := word1 + word3 + word2
    perm3 := word2 + word1 + word3
    perm4 := word2 + word3 + word1
    perm5 := word3 + word2 + word1
    perm6 := word3 + word1 + word2

    // Reading the number of students
    students, _ := in.ReadString('\n')
    // This block of code reads a line from the user input and stores it in the'students' variable.
    // The '\n' character is used as the delimiter to read the entire line.

    // Looping through each student's test case
    for i := 0; i < len(students); i++ {
        // Reading a test case from the user input
        testCase, _ := in.ReadString('\n')
        // This block of code reads a line from the user input and stores it in the 'testCase' variable.
        // The '\n' character is used as the delimiter to read the entire line.

        // Checking if the test case matches any of the permutations
        if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
            // Printing 'ACC' if the test case matches any of the permutations
            fmt.Println("ACC")
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            fmt.Println("WA")
        }
    }

    // Closing the Scanner object
    in.Close()
}

