package main

import (
    "fmt"
    "math"
)

func main() {
    var r float64
    fmt.Scanf("%f", &r)
    fmt.Printf("%f %f\n", math.Pow(r, 2)*math.Pi, 2*math.Pi*r)
}

