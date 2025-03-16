package main

import "fmt"

func main() {
    // Declare a character array to hold the input string
    var n [10]byte

    // Read a string from standard input and store it in the array 'n'
    fmt.Scanf("%s", &n)

    // Check if the first three characters are the same or if the last three characters are the same
    if (((n[0] == n[1]) && (n[1] == n[2])) || ((n[1] == n[2]) && (n[2] == n[3]))) {
        // If the condition is true, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No"
        fmt.Println("No")
    }
}

