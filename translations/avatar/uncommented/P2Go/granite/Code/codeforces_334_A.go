
package main

import "fmt"

func main() {
    n := 5
    i, j := 1, n*n
    for i < j {
        fmt.Printf("%d %d\n", i, j)
        i++
        j--
    }
}
