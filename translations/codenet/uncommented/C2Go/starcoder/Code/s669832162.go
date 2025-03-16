package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var m1, d1, m2, d2 int
    fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d%d%d%d", &m1, &d1, &m2, &d2)
    if m1!= m2 {
        fmt.Println("1")
    } else {
        fmt.Println("0")
    }
}

