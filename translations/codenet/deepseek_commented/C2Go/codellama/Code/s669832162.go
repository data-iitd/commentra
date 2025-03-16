package main

import "fmt"

func main() {
    var m1, d1, m2, d2 int // Declare four integer variables to store month and day values
    fmt.Scanf("%d%d%d%d", &m1, &d1, &m2, &d2) // Read four integer values from the standard input
    if m1 != m2 { fmt.Println("1") } // Check if the values of m1 and m2 are not equal, if true print 1
    else { fmt.Println("0") } // If m1 and m2 are equal, print 0
}

