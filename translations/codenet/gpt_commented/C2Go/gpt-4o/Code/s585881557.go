package main

import (
    "fmt"
)

func main() {
    // Declare two integer variables h and r
    var h, r int

    // Read two integers from standard input
    fmt.Scanf("%d%d", &h, &r)

    // Compare the value of r with -h
    if r > -h {
        // If r is greater than -h, print "1"
        fmt.Println("1")
    } else if r == -h {
        // If r is equal to -h, print "0"
        fmt.Println("0")
    } else {
        // If r is less than -h, print "-1"
        fmt.Println("-1")
    }
}

// <END-OF-CODE>
