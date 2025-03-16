package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of test cases
    tcs := 1
    // Start with the first test case
    tc := 1

    // Loop through each test case until the specified number of test cases is reached
    for tc <= tcs {
        // Read an integer from standard input and strip any extra whitespace
        a := strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString())
        // Convert the string to an integer
        a, _ := strconv.Atoi(a)

        // Print 1 if the integer is 0, otherwise print 0
        fmt.Printf("%d\n", 1 if a == 0 else 0)

        // Increment the test case counter
        tc++
    }
}

