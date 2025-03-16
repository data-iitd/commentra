package main

import "fmt"

func main() {
    var A, B int
    var ans int = 0
    var out int = 1

    fmt.Scan(&A, &B)

    for out < B {
        out--
        out += A
        ans++
    }
    fmt.Println(ans)
}

