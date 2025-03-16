<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n, a, b int64
    fmt.Scanf("%d", &n)
<<<<<<< HEAD
    for i := int64(1); i <= n; i++ {
=======
    for i := int64(0); i < n; i++ {
>>>>>>> 98c87cb78a (data updated)
        a += i
    }
    b = a * (n - 1) / 2
    fmt.Printf("%d\n", b)
}

