
package main

import "fmt"

func main() {
    var t, a, b, c, count int
    fmt.Scan(&t) // Reading the number of test cases
    for t > 0 {
        fmt.Scan(&a, &b, &c) // Reading the three integers for each test case
        if a == 1 || b == 1 || c == 1 {
            count++ // Incrementing the count if at least one of the integers is equal to 1
        }
        t-- // Decrementing the test case counter
    }
    fmt.Println(count) // Outputting the total count of valid cases
}

