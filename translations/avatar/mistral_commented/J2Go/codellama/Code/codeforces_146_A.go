
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    var x, y, t, n int
    var str string
    var l []rune

    fmt.Scan(&n)
    fmt.Scan(&str)

    l = []rune(str)

    for i := 0; i < n; i++ {
        if l[i] != '4' && l[i] != '7' {
            t = 1
        }
    }

    if t == 1 {
        fmt.Println("NO")
    } else {
        var sumX, sumY int

        for i := 0; i < n/2; i++ {
            x = x + int(l[i]) - int('0')
        }

        for i := n - 1; i > n/2 - 1; i-- {
            y = y + int(l[i]) - int('0')
        }

        if x == y {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}

