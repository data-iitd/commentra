package main

import (
    "fmt"
)

func main() {
    var x int
    fmt.Scan(&x)
    if x >= 1200 {
        fmt.Println("ARC")
    } else {
        fmt.Println("ABC")
    }
}

// <END-OF-CODE>
