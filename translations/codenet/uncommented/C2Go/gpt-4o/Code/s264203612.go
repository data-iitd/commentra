package main

import (
    "fmt"
)

func main() {
    var r, s, l float64
    p := 3.141592653589

    fmt.Scanf("%lf", &r)

    s = r * r * p
    l = 2 * p * r

    fmt.Printf("%f %f\n", s, l)
}

// <END-OF-CODE>
