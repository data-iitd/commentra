package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold the month and day values for two dates
    var m1, d1, m2, d2 int

    // Read input values for the two dates (month and day)
    fmt.Scanf("%d%d%d%d", &m1, &d1, &m2, &d2)

    // Compare the months of the two dates
    if m1!= m2 {
        // If the months are different, print "1"
        fmt.Println("1")
    } else {
        // If the months are the same, print "0"
        fmt.Println("0")
    }
}

