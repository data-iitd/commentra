
package main

import (
    "fmt"
    "strconv"
    "strings"
)

func main() {
    var n int
    var a []int
    fmt.Scan(&n)
    fmt.Scan(&a)
    a = strings.Split(a, " ")
    for i := 0; i < len(a); i++ {
        a[i], _ = strconv.Atoi(a[i])
    }
    if sum(a)%(n*(n+1)/2) != 0 {
        fmt.Println("NO")
    } else {
        k := sum(a) / (n * (n + 1) / 2)
        a = append(a, a[0])
        for i := 1; i < len(a); i++ {
            if (k-a[i]+a[i-1])%n != 0 || (k-a[i]+a[i-1])/n < 0 {
                fmt.Println("NO")
                return
            }
        }
        fmt.Println("YES")
    }
}

func sum(a []int) int {
    var s int
    for i := 0; i < len(a); i++ {
        s += a[i]
    }
    return s
}

