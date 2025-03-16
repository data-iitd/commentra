package main

import (
    "fmt"
)

func main() {
    i := 1
    var input int

    for {
        fmt.Scan(&input)
        if input == 0 {
            break
        }
        fmt.Printf("Case %d: %d\n", i, input)
        i++
    }
}

// <END-OF-CODE>
