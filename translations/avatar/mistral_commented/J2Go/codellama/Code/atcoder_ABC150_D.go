
package main

import (
    "fmt"
    "strconv"
)

func main() {
    var n, m int
    fmt.Scan(&n, &m)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
        a[i] /= 2
    }

    var gcd, lcd int = 1, 1
    for i := 0; i < n; i++ {
        gcd = getGCD(lcd, a[i])
        lcd *= a[i] / gcd
        if lcd > m {
            fmt.Println(0)
            return
        }
    }

    for i := 0; i < n; i++ {
        if lcd/a[i]%2 == 0 {
            fmt.Println(0)
            return
        }
    }

    fmt.Println(m/lcd+1)/2)
}

func getGCD(a, b int) int {
    if b == 0 {
        return a
    }
    return getGCD(b, a%b)
}

