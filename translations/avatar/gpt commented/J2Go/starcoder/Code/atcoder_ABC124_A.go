package main

import "fmt"

func main() {
    var a, b, sum int
    fmt.Scanf("%d %d", &a, &b)
    for i := 0; i < 2; i++ {
        if a >= b {
            sum += a
            a--
        } else {
            sum += b
            b--
        }
    }
    fmt.Println(sum)
}

