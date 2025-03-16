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
    var m1, d1, m2, d2 int
    fmt.Scanf("%d%d%d%d", &m1, &d1, &m2, &d2)
    if m1!= m2 {
        fmt.Println("1")
    } else {
        fmt.Println("0")
    }
}

