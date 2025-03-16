
package main

import "fmt"

func main() {
    i := 1
    for {
        var input int
        fmt.Scan(&input)
        if input == 0 {
            break
        }
        fmt.Printf("Case %d: %d\n", i, input)
        i++
    }
}
// 