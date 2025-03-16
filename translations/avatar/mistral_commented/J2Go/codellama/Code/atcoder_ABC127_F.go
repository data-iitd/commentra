
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    var t int
    fmt.Scan(&t)
    for i := 0; i < t; i++ {
        var n int
        fmt.Scan(&n)
        var a []int
        for j := 0; j < n; j++ {
            var x int
            fmt.Scan(&x)
            a = append(a, x)
        }
        sort.Ints(a)
        var sum int
        for j := 0; j < n; j++ {
            sum += a[j]
        }
        fmt.Println(sum)
    }
}

