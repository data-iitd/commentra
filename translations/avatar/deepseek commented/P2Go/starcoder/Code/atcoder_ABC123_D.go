
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    var x, y, z, k int
    fmt.Scanf("%d %d %d %d", &x, &y, &z, &k)
    a := make([]int, x)
    b := make([]int, y)
    c := make([]int, z)
    ab := make([]int, x*y)
    for i := 0; i < x; i++ {
        fmt.Scanf("%s", &a)
        for j := 0; j < y; j++ {
            ab[i*y+j] = a[i] + b[j]
        }
    }
    sort.Slice(ab, func(i, j int) bool { return ab[i] > ab[j] })
    abc := make([]int, min(k, x*y))
    for i := 0; i < min(k, x*y); i++ {
        for j := 0; j < z; j++ {
            abc[i] = ab[i] + c[j]
        }
    }
    sort.Slice(abc, func(i, j int) bool { return abc[i] > abc[j] })
    for i := 0; i < k; i++ {
        fmt.Printf("%d\n", abc[i])
    }
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

