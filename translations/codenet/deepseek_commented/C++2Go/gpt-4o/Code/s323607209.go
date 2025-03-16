package main

import (
    "fmt"
)

func main() {
    var n, k int
    var l, r int64 = 0, 0  // Declare integer variables for counting

    fmt.Scanf("%d%d", &n, &k)  // Read input values for n and k

    if k%2 == 0 {  // Check if k is even
        for i := 1; i <= n; i++ {  // Iterate from 1 to n
            if i%k == k/2 {  // Check if i modulo k equals k/2
                l++  // Increment l if condition is true
            } else if i%k == 0 {  // Check if i modulo k equals 0
                r++  // Increment r if condition is true
            }
        }
        fmt.Println(l*l*l + r*r*r)  // Print the result of l^3 + r^3
    } else {  // If k is odd
        for i := 1; i <= n; i++ {  // Iterate from 1 to n
            if i%k == 0 {  // Check if i modulo k equals 0
                r++  // Increment r if condition is true
            }
        }
        fmt.Println(r * r * r)  // Print the result of r^3
    }
}

// <END-OF-CODE>
