package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n int
    var a [100]int
    var avg float64
    var s float64
    var ans int

    fmt.Scanf("%d", &n)

    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
        avg += float64(a[i])
    }

    avg /= float64(n)

    s = float64(abs(a[0] - int(avg)))
    ans = 0

    for i := 1; i < n; i++ {
        if s > float64(abs(a[i] - int(avg))) {
            s = float64(abs(a[i] - int(avg)))
            ans = i
        }
    }

    fmt.Println(ans)
}

