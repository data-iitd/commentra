package main

import "fmt"

func main() {
    // Declare variables for input
    var i, t, n int

    // Loop to process 4 test cases
    for i = 0; i < 4; i++ {
        // Read the type (t) and quantity (n) from input
        fmt.Scanf("%d %d", &t, &n)

        // Calculate and output the result based on the type (t)
        if t == 1 {
            // If type is 1, multiply n by 6000
            fmt.Println(6000 * n)
        } else if t == 2 {
            // If type is 2, multiply n by 4000
            fmt.Println(4000 * n)
        } else if t == 3 {
            // If type is 3, multiply n by 3000
            fmt.Println(3000 * n)
        } else if t == 4 {
            // If type is 4, multiply n by 2000
            fmt.Println(2000 * n)
        }
    }
}

