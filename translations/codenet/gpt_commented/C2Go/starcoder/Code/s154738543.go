package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var x, y int
    fmt.Scanf("%d", &x)
    y = x * x * x
    fmt.Printf("%d\n", y)
}

