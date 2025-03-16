
package main

import (
    "fmt"
    "sort"
    "strconv"
    "strings"
)

func main() {
    var n, x int
    fmt.Scan(&n, &x)

    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }

    sort.Ints(a)

    ans := 0
    for i := 0; i < n; i++ {
        if a[i] > x {
            break
        }
        x -= a[i]
        ans++
    }

    if x != 0 {
        ans--
    }

    fmt.Println(ans)
}

