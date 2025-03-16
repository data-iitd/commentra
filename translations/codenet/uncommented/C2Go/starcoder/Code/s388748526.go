package main

import (
    "fmt"
    "math"
)

func main() {
    var r float64
    fmt.Scanf("%lf", &r)
    fmt.Printf("%.10f %.10f\n", r*r*math.Pi, 2*math.Pi*r)
}
