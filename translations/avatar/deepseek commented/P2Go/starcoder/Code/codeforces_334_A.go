
package main

import "fmt"

func main() {
    var n int
    fmt.Scanf("%d", &n)
    i, j := 1, n*n
    for i < j {
        fmt.Printf("%d %d\n", i, j)
        i++
        j--
    }
}

