package main

import "fmt"

const p = 3.141592653589

func main() {
    var r float64
    var s, l float64

    fmt.Scan(&r)

    s = r * r * p
    l = 2 * p * r

    fmt.Println(s, l)
}

