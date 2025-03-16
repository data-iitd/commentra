package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var x int
    fmt.Scanf("%d", &x)
    if x >= 1200 {
        fmt.Println("ARC")
    } else {
        fmt.Println("ABC")
    }
}

