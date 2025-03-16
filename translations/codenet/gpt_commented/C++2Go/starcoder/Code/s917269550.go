package main

import (
    "fmt"
    "math"
)

func main() {
    var x, y int64

    fmt.Scan(&x, &y)

    if math.Abs(float64(x-y)) <= 1 {
        fmt.Println("Brown")
    } else {
        fmt.Println("Alice")
    }
}

