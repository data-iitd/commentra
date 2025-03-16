<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n int
    fmt.Scanf("%d", &n)
    if n%2 == 0 {
        fmt.Println(n/2)
    } else {
        fmt.Println((n/2)+1)
    }
}

