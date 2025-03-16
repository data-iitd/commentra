
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
    var n int
    fmt.Scan(&n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    sort.Ints(a)
    a = a[:len(a)-1]
    for i := 0; i < len(a)-2; i++ {
        if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
            fmt.Println("YES")
            return
        }
    }
    fmt.Println("NO")
}

