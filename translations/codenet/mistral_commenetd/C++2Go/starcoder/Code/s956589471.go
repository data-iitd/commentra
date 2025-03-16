
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a, b, c, d, e, k int
    fmt.Scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k)
    if e-a <= k {
        fmt.Println("Yay!")
    } else {
        fmt.Println(":(")
    }
}

