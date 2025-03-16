
package main

import "fmt"

func main() {
    var i, N, x int
    fmt.Scan(&N)
    for i = 1; i <= N; i++ {
        x += i
    }
    fmt.Println(x)
}

