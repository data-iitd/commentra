

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read an integer K from the user
    scanner.Scan()
    K, _ := strconv.Atoi(scanner.Text())

    // Read a string S from the user
    scanner.Scan()
    S := scanner.Text()

    // Check if the length of the string S is less than or equal to K
    if len(S) <= K {
        // If true, print the string S as it is
        fmt.Println(S)
    } else {
        // If false, truncate the string to the first K characters and append "..."
        fmt.Println(S[:K] + "...")
    }
}

