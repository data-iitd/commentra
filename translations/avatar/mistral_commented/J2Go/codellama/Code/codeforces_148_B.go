package main

import (
    "fmt"
    "os"
)

func main() {
    var VP, VD, T, F, C float64
    var answer int
    var start float64

    fmt.Scan(&VP, &VD, &T, &F, &C)

    if VD <= VP {
        fmt.Println(0)
        os.Exit(0)
    }

    answer = 0
    start = T

    for {
        x := start * VP / (VD - VP)

        if (start + x) * VP >= C {
            break
        }

        start += 2 * x + F
        answer++
    }

    fmt.Println(answer)
}

