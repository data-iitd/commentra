
package main

import "fmt"

func main() {
    // Take an integer input from the user and assign it to the variable n
    var n int
    fmt.Scan(&n)

    // Iterate n times
    for i := 0; i < n; i++ {
        // Take an integer input from the user and assign it to the variable a
        var a int
        fmt.Scan(&a)

        // Check if a is less than 2
        if a < 2 {
            // If a is less than 2, print 0
            fmt.Println(0)

            // Move to the next iteration of the loop
            continue
        }

        // If a is not less than 2, check if it is greater than or equal to 2
        if a >= 2 {
            // If a is greater than or equal to 2, print a - 2
            fmt.Println(a - 2)
        }
    }
}
