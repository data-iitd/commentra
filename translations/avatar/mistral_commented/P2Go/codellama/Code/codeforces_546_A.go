
package main

import "fmt"

func main() {
    var k, n, w int
    fmt.Scan(&k, &n, &w)

    if 1 <= k && w <= 1000 {
        total := 0
        for i := 1; i <= w; i++ {
            total += k * i
        }

        if total > n {
            fmt.Println(total - n)
        } else {
            fmt.Println(0)
        }
    }
}

