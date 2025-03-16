package main

import (
    "fmt"
)

func main() {
    // Read two integers from input: S (the strength) and W (the weight)
    var S, W int
    fmt.Scan(&S, &W)

    // Check if the strength S is less than or equal to the weight W
    // If it is, print "unsafe"; otherwise, print "safe"
    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}

// <END-OF-CODE>
