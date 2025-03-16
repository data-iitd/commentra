
package main

import "fmt"

func main() {
    var a, b int
    fmt.Scan(&a, &b)
    fmt.Printf("%d %d\n", a*b, 2*(a+b))
}

