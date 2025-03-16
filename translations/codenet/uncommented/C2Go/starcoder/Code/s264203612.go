package main

import (
    "fmt"
    "math"
)

func main() {
    var r float64
    fmt.Scanf("%f", &r)
    s := r * r * math.Pi
    l := 2 * math.Pi * r
    fmt.Printf("%f %f\n", s, l)
}

