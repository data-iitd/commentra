
package main

import "fmt"

func main() {
    var k, n, w string
    fmt.Scan(&k, &n, &w)
    if 1 <= len(k) && len(w) <= 1000 {
        total := 0
        for i := 1; i <= len(w); i++ {
            total += i * len(k)
        }
        if total > len(n) {
            fmt.Println(total - len(n))
        } else {
            fmt.Println(0)
        }
    }
}

