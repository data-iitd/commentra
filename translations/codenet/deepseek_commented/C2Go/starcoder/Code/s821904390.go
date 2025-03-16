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
    var in int
    fmt.Scanf("%d", &in)
    h := in / 3600
    in %= 3600
    m := in / 60
    in %= 60
    s := in
    fmt.Printf("%d:%d:%d\n", h, m, s)
}

