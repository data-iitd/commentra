package main

import "fmt"

func main() {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)
    count := 0
    for a > 0 && b > 0 {
        count++
        a--
        b--
    }
    ans := a/2 + b/2
    fmt.Printf("%d %d\n", count, ans)
}

