
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    var A, B, n int
    var neg bool

    if _, err := fmt.Scan(&A, &B, &n); err != nil {
        fmt.Println(err)
        os.Exit(1)
    }

    if A == 0 {
        if B == 0 {
            fmt.Println(1)
        } else {
            fmt.Println("No solution")
        }
        return
    }

    if B%A != 0 {
        fmt.Println("No solution")
        return
    }

    B /= A
    neg = B < 0

    if neg && n%2 == 0 {
        fmt.Println("No solution")
        return
    }

    if neg {
        B = -B
    }

    for x := 0; x <= B; x++ {
        if math.Pow(float64(x), float64(n)) == float64(B) {
            if neg {
                fmt.Println(-x)
            } else {
                fmt.Println(x)
            }
            return
        }
    }

    fmt.Println("No solution")
}

