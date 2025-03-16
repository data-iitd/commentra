package main

import (
    "fmt"
    "math"
)

func main() {
    var N int
    fmt.Scan(&N)

    pos := make([][]int, N)
    for i := 0; i < N; i++ {
        pos[i] = make([]int, 2)
        fmt.Scan(&pos[i][0])
        fmt.Scan(&pos[i][1])
    }

    sum := 0.0
    for i := 0; i < N; i++ {
        for j := 0; j < N; j++ {
            if i == j {
                continue
            }
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
        }
    }

    fmt.Println(sum / N)
}

func dist(x1, y1, x2, y2 int) float64 {
    return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

