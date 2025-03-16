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
    var A, B, C, X int
    var i, j, k int
    var kosu int

    fmt.Scanf("%d", &A)
    fmt.Scanf("%d", &B)
    fmt.Scanf("%d", &C)
    fmt.Scanf("%d", &X)

    X = X / 50

    for i = 0; i <= A; i++ {
        for j = 0; j <= B; j++ {
            for k = 0; k <= C; k++ {
                if X == (10 * i) + (2 * j) + k {
                    kosu++
                }
            }
        }
    }

    fmt.Printf("%d\n", kosu)
}

