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
    var a, b, result int
    fmt.Scanf("%d", &a)
    fmt.Scanf("%d", &b)

    if a > b {
        result = 2*a - 1
    } else if a == b {
        result = 2*a
    } else {
        result = 2*b - 1
    }

    fmt.Println(result)
}

