package main

import (
    "fmt"
)

func main() {
    var A, B int
    fmt.Scan(&A, &B)

    if A < 13 && A >= 6 {
        fmt.Println(B / 2)
    }
    if A < 6 {
        fmt.Println(0)
    }
    if A >= 13 {
        fmt.Println(B)
    }
}

// <END-OF-CODE>
