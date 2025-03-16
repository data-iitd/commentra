package main

import (
    "fmt"
)

func main() {
    var n, k int // Declare two integer variables n and k
    var l, r int64 = 0, 0 // Initialize l and r to zero

    fmt.Scanf("%d%d", &n, &k) // Read two integers n and k from the standard input

    if k%2 == 0 { // Check if k is even
        for i := 1; i <= n; i++ { // Iterate through the numbers from 1 to n
            if i%k == k/2 { // Check if the remainder of i divided by k is equal to k/2
                l++ // If it is, increment the variable l by 1
            } else if i%k == 0 { // Else if the remainder of i divided by k is equal to 0
                r++ // Increment the variable r by 1
            }
        }
        fmt.Println(l*l*l + r*r*r) // Calculate and print the result using the expressions l*l*l+r*r*r
    } else { // Else if k is odd
        for i := 1; i <= n; i++ { // Iterate through the numbers from 1 to n
            if i%k == 0 { // Check if the remainder of i divided by k is equal to 0
                r++ // If it is, increment the variable r by 1
            }
        }
        fmt.Println(r * r * r) // Calculate and print the result using the expression r*r*r
    }
}

// <END-OF-CODE>
