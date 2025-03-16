
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read an integer input from the user
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())

    // Read a string input from the user
    scanner.Scan()
    s := scanner.Text()

    // Check if n is odd
    if n%2!= 0 {
        // Print 'No' if n is odd
        fmt.Println("No")
    } else {
        // If n is even, compare the first half of the string with the second half
        if s[:n/2] == s[n/2:] {
            // Print 'Yes' if the first half is equal to the second half
            fmt.Println("Yes")
        } else {
            // Print 'No' if the first half is not equal to the second half
            fmt.Println("No")
        }
    }
}
