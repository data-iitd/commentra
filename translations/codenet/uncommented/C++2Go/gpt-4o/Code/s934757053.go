package main

import (
    "fmt"
)

func main() {
    var A, B int
    ans := 0
    out := 1
    fmt.Scan(&A, &B)

    for out < B {
        out--
        out += A
        ans++
    }
    fmt.Println(ans)
}

// <END-OF-CODE>
