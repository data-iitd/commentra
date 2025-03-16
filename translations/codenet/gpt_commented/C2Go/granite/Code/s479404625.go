
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare character arrays to hold three strings
    var A, B, C string

    // Create a scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read three strings from user input
    scanner.Scan()
    A = scanner.Text()
    scanner.Scan()
    B = scanner.Text()
    scanner.Scan()
    C = scanner.Text()

    // Calculate the lengths of the first two strings
    la := len(A)
    lb := len(B)

    // Check if the last character of A is the same as the first character of B
    // and if the last character of B is the same as the first character of C
    if A[la-1] == B[0] && B[lb-1] == C[0] {
        // If both conditions are true, print "YES"
        fmt.Println("YES")
    } else {
        // If either condition is false, print "NO"
        fmt.Println("NO")
    }
}

