<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
<<<<<<< HEAD
    var n, m, x int
    fmt.Scanf("%d %d %d", &n, &m, &x)

    a := make([]int, n+1)
    for i := 0; i < m; i++ {
        var temp int
        fmt.Scanf("%d", &temp)
        a[temp] = 1
    }

    ansl := 0
    ansr := 0
    for i := x; i <= n; i++ {
        ansr += a[i]
    }
    for i := x; i >= 0; i-- {
        ansl += a[i]
    }

=======
    n, m, x := 0, 0, 0
    a := make([]int, 105)
    fmt.Scanf("%d %d %d", &n, &m, &x)
    for i := 0; i < m; i++ {
        temp := 0
        fmt.Scanf("%d", &temp)
        a[temp] = 1
    }
    ansl, ansr, i := 0, 0, 0
    for i = x; i <= n; i++ {
        ansr += a[i]
    }
    for i = x; i >= 0; i-- {
        ansl += a[i]
    }
>>>>>>> 98c87cb78a (data updated)
    fmt.Printf("%d\n", min(ansl, ansr))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

