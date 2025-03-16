package main

import (
    "fmt"
)

func main() {
    var n, b uint64
    fmt.Scanf("%llu", &n)
    b = (n * (n - 1)) / 2
    fmt.Println(b)
}

// <END-OF-CODE>
