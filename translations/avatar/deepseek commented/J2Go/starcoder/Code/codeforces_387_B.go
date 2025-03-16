_
package main

import "fmt"

func main() {
    var n, m int
    fmt.Scanf("%d %d", &n, &m)
    req := make([]int, n)
    pre := make([]int, m)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &req[i])
    }
    for i := 0; i < m; i++ {
        fmt.Scanf("%d", &pre[i])
    }
    i := n - 1
    j := m - 1
    ans := 0
    for i >= 0 && j >= 0 {
        if req[i] > pre[j] {
            ans++
        } else {
            j--
        }
        i--
    }
    fmt.Printf("%d", ans + i + 1)
}

