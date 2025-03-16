package main

import "fmt"

func main() {
    var n, a, b uint64
    var i, j int

    fmt.Scanf("%d", &n)

    b = (n * (n - 1)) / 2

    fmt.Println(b)
}

