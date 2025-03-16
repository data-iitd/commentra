package main

import "fmt"

func main() {
    var n int
    fmt.Scanf("%d", &n)

    var p [1000010]int
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &p[i])
    }

    ans := 0
    for i := 0; i < n-2; i++ {
        if p[i] > p[i+1] && p[i+1] > p[i+2] {
            ans++
        }
        if p[i] < p[i+1] && p[i+1] < p[i+2] {
            ans++
        }
    }

    fmt.Println(ans)
}

