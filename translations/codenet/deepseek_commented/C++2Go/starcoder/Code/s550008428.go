<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

func main() {
    s := 0
    x := 0
    d := 2
    a := make(map[int]bool)

    fmt.Scanf("%d", &s)
    a[s] = true

    for {
        if s%2 == 0 {
            x = s/2
            if a[x] {
                fmt.Println(d)
                return
            }
            a[x] = true
        } else {
            x = 3*s + 1
            if a[x] {
                fmt.Println(d)
                return
            }
            a[x] = true
        }
        s = x
        d++
    }

    fmt.Println(d)
}

