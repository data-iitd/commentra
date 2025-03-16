
package main

import "fmt"

func main() {
    var i, t, n int
    for i = 0; i < 4; i++ {
        fmt.Scan(&t, &n)
        switch t {
        case 1:
            fmt.Println(6000 * n)
        case 2:
            fmt.Println(4000 * n)
        case 3:
            fmt.Println(3000 * n)
        case 4:
            fmt.Println(2000 * n)
        }
    }
}

