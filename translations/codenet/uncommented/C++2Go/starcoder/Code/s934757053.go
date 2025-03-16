package main

import "fmt"

func main() {
    var A, B int
    var ans, out int
    fmt.Scanf("%d %d", &A, &B)

    for out = 1; out < B; out++ {
        out -= A
        out += A
        ans++
    }
    fmt.Println(ans)
}

