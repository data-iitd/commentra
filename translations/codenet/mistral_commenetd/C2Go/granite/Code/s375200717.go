
package main

import "fmt"

func main() {
    var n, i, a int
    fmt.Scan(&n)
    for i = 1; i <= n; i++ {
        a = i
        if a%3 == 0 {
            fmt.Printf(" %d", i)
        } else {
            for a!= 0 {
                if a%10 == 3 {
                    fmt.Printf(" %d", i)
                    a = 0
                }
                a = a / 10
            }
        }
    }
    fmt.Println()
}

