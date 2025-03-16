package main

import (
    "fmt"
    "math"
)

func main() {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)
    fmt.Printf("%d\n", int(math.Max(float64(a+b), math.Max(float64(a-b), float64(a*b)))))
}

