package main

import (
    "fmt"
)

func main() {
    i := 1
    for {
        var Input int
        fmt.Scan(&Input)
        if Input == 0 {
            break
        }
        fmt.Printf("Case %d: %d\n", i, Input)
        i++
    }
}

