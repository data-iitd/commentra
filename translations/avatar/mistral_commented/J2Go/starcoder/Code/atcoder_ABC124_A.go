package main

import "fmt"
import "os"
import "strconv"

func main() {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)
    sum := 0
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

