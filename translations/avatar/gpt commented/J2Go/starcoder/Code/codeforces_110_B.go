package main

import "fmt"

func main() {
    var n, i, j, p int = 97
    var c [10000]byte

    for i = 0; i < 4; i++ {
        for j = i; j < n; j += 4 {
            c[j] = byte(p)
            p++
        }
    }

    for i = 0; i < n; i++ {
        fmt.Printf("%c", c[i])
    }
}

