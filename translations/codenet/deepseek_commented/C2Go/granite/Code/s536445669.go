
package main

import "fmt"

func main() {
        var n, k int
        fmt.Scan(&n, &k)  // Read two integers from the standard input
        if n%k == 0 {     // Check if n is divisible by k
            fmt.Println(0)  // If true, print 0
        } else {
            fmt.Println(1)  // If false, print 1
        }
}

