package main

import "fmt"

func main() {
    var n int
    fmt.Scanf("%d", &n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    sort.Ints(a)
    for i := 0; i < n-1; i++ {
        if a[i] == a[i+1] {
            fmt.Println("NO")
            return
        }
    }
    fmt.Println("YES")
}

