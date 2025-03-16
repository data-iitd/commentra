
package main

import (
    "fmt"
    "math"
)

func main() {
    // Reading the first two integers from the input
    var n, m int
    fmt.Scan(&n, &m)

    // Creating an integer array 'a' of size 'm'
    a := make([]int, m)

    // Checking if 'n' is divisible by 'm'
    if n%m == 0 {
        // If 'n' is divisible by 'm', then 'n' can be divided evenly by 'm'
        // So, all elements of 'a' will be equal to the quotient of 'n' and 'm'
        for i := 0; i < len(a); i++ {
            a[i] = n / m
        }
    } else {
        // If 'n' is not divisible by 'm', then 'n' can't be divided evenly by 'm'
        // So, we need to calculate the quotient 'sub' and the remainder 'test' of 'n' by 'm'
        sub := n / m

        // All elements of 'a' will be equal to 'sub', except for some elements at the end
        for i := 0; i < len(a); i++ {
            a[i] = sub
        }

        // Calculating the number of extra elements needed at the end of 'a'
        test := n - (sub * m)

        // Adding '1' to each extra element of 'a'
        count := 0
        for i := 0; i < test; i++ {
            a[count] = a[count] + 1
            count++

            // If we reach the end of 'a', then we reset the index to '0'
            if count > len(a) {
                count = 0
            }
        }
    }

    // Printing the elements of 'a' in reverse order
    for i := len(a) - 1; i >= 0; i-- {
        fmt.Print(a[i], " ")
    }
}

