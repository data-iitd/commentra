
package main

import "fmt"

func main() {
    var x, y int
    fmt.Scan(&x, &y)
    fmt.Printf("%d %d\n", x*y, 2*x+2*y)
}

