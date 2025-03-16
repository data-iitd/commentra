
package main

import "fmt"

func main() {
    var x int
    fmt.Scan(&x)
    if x == 0 {
        fmt.Println(1)
    } else if x == 1 {
        fmt.Println(0)
    }
    // 