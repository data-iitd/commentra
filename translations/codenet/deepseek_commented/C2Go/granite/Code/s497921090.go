
package main

import "fmt"

func main() {
    var n, a, b uint64 = 0, 0, 0
    fmt.Scanf("%d", &n)
    b = (n * (n - 1)) / 2
    fmt.Printf("%d\n", b)
}

