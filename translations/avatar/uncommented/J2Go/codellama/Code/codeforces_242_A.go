
package main

import "fmt"
import "os"

func main() {
    var x, y, a, b int
    fmt.Scan(&x, &y, &a, &b)
    var count int
    for i := a; i <= x; i++ {
        for j := b; j <= y; j++ {
            if i <= j {
                continue
            }
            count++
        }
    }
    fmt.Println(count)
    for i := a; i <= x; i++ {
        for j := b; j <= y; j++ {
            if i <= j {
                continue
            }
            fmt.Println(i, j)
        }
    }
    os.Exit(0)
}

