package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)
    fmt.Printf("%d %d\n", a*b, 2*(a+b))
}

