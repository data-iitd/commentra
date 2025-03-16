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
    var S int
    fmt.Scanf("%d", &S)
    fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60)
}

