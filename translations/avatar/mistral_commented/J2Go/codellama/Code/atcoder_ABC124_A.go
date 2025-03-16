package main

import (
    "fmt"
    "strconv"
)

func main() {
    var a, b int
    var sum int

    fmt.Scan(&a, &b)

    for i := 0; i < 2; i++ {
        if a >= b {
            sum += a
            a--
        } else {
            sum += b
            b--
        }
    }

    fmt.Println(sum)
}

