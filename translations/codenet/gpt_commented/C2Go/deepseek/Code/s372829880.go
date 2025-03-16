package main

import "fmt"

func main() {
    // Declare two integer variables x and a
    var x, a int

    // Read two integer values from user input and store them in x and a
    fmt.Scan(&x, &a)

    // Check if x is greater than or equal to a
    // If true, print 10; otherwise, print 0
    fmt.Println((x >= a) * 10)
}

