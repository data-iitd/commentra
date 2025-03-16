<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n int
    fmt.Scanf("%d", &n)
    p := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &p[i])
    }
    ans := 0
    for i := 0; i < n-1; i++ {
        if p[i] == i+1 {
            p[i+1] = p[i]
            ans += 1
        }
    }
    if p[n-1] == n {
        ans += 1
    }
    fmt.Println(ans)
}

