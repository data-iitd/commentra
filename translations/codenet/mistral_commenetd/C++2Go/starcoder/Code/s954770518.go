<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "sort"
)

func main() {
    var s [11]int
    var i int

    for i = 0; i < 10; i++ {
        fmt.Scanf("%d", &s[i])
    }

    sort.Ints(s[:])

    for i = 9; i > 6; i-- {
        fmt.Println(s[i])
    }
}
