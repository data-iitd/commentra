
package main

import (
    "fmt"
    "math"
)

func main() {
    var r float64
    fmt.Scan(&r)
    area := r * r * math.Pi
    circumference := 2 * math.Pi * r
    fmt.Printf("%f %f\n", area, circumference)
}

