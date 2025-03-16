

package main

import "fmt"

func main() {
    var n [10]byte
    // The fmt.Scanf function is used to read a string of characters from the standard input stream
    fmt.Scanf("%s", n[:])

    // Check if the first three characters of the input string form an identical sequence
    if ((n[0] == n[1]) && (n[1] == n[2])) || ((n[1] == n[2]) && (n[2] == n[3])) {
        // If the condition is true, print "Yes" to the standard output stream
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No" to the standard output stream
        fmt.Println("No")
    }
}

// 