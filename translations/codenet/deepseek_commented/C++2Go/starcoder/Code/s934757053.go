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
    var A, B int
    var ans int
    var out int = 1

    fmt.Scanf("%d %d", &A, &B)

    for out < B {
        out--
        out += A
        ans++
    }
    fmt.Println(ans)
}

