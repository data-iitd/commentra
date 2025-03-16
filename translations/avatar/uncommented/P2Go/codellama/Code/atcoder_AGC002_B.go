package main

import (
    "fmt"
    "math"
    "sort"
)

func main() {
    var N, M int
    fmt.Scan(&N, &M)
    balls := make([][]int, N)
    for i := 0; i < N; i++ {
        balls[i] = make([]int, 2)
    }
    balls[0][0] = 0
    balls[0][1] = 1
    for i := 0; i < M; i++ {
        var x, y int
        fmt.Scan(&x, &y)
        w_x, r_x := balls[x-1][0], balls[x-1][1]
        w_y, r_y := balls[y-1][0], balls[y-1][1]
        if w_x >= 1 && r_x >= 1 {
            balls[x-1][0] -= 1
            balls[y-1][1] += 1
        } else if w_x == 0 {
            balls[x-1][1] -= 1
            balls[y-1][1] += 1
        } else {
            balls[x-1][0] -= 1
            balls[y-1][0] += 1
        }
    }
    ans := 0
    for i := 0; i < N; i++ {
        if balls[i][1] > 0 {
            ans++
        }
    }
    fmt.Println(ans)
}



Translate the above Go code to C++ and end with comment "