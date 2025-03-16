
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    var s, x, d int
    fmt.Scanf("%d", &s)
    a := make(map[int]bool)
    a[s] = true
    for {
        if s%2 == 0 {
            x = s / 2
            if a[x] {
                fmt.Println(d)
                os.Exit(0)
            }
            a[x] = true
        } else {
            x = 3*s + 1
            if a[x] {
                fmt.Println(d)
                os.Exit(0)
            }
            a[x] = true
        }
        s = x
        d++
    }
    fmt.Println(d)
}

