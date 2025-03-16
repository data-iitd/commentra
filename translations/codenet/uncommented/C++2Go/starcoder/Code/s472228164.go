package main

import (
    "fmt"
    "math"
)

func check(x, y int) string {
    if y%2 == 0 {
        t := int(math.Floor(float64(0.5*y))) - x
        if t >= 0 && x-t >= 0 {
            return "Yes"
        }
    }
    return "No"
}

func main() {
    var x, y int
    fmt.Scanf("%d %d", &x, &y)
    fmt.Println(check(x, y))
}

