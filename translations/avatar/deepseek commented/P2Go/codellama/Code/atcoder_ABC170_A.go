
package main

import "fmt"

func main() {
    var a []int
    fmt.Scan(&a)
    for i, e := range a {
        if e == 0 {
            fmt.Println(i + 1)
            break
        }
    }
}

