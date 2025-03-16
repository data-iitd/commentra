
package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    if sum(a)%(n*(n+1)/2) != 0 {
        fmt.Println("NO")
    } else {
        k := sum(a) / (n * (n + 1) / 2)
        a = append(a, a[0])
        if sum([]int{k - a[1] + a[0], k - a[2] + a[1], k - a[3] + a[2], k - a[4] + a[3], k - a[5] + a[4], k - a[6] + a[5], k - a[7] + a[6], k - a[8] + a[7], k - a[9] + a[8], k - a[10] + a[9]}) != 0 || sum([]int{(k - a[1] + a[0]) / n, (k - a[2] + a[1]) / n, (k - a[3] + a[2]) / n, (k - a[4] + a[3]) / n, (k - a[5] + a[4]) / n, (k - a[6] + a[5]) / n, (k - a[7] + a[6]) / n, (k - a[8] + a[7]) / n, (k - a[9] + a[8]) / n, (k - a[10] + a[9]) / n}) != n {
            fmt.Println("NO")
        } else {
            fmt.Println("YES")
        }
    }
}

func sum(a []int) int {
    var s int
    for _, v := range a {
        s += v
    }
    return s
}

