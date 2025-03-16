package main

import "fmt"

func main() {
    var a, b, c, d int
    fmt.Scan(&a, &b, &c, &d)
    i, j := a*b, c*d
    if i > j {
        fmt.Println(i)
    } else {
        fmt.Println(j)
    }
}

