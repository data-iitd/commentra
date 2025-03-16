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
    var n, k int
    fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d %d", &n, &k)
    var l, r int
    for i := 1; i <= n; i++ {
        if i%k == k/2 {
            l++
        } else if i%k == 0 {
            r++
        }
    }
    fmt.Println(l*l*l + r*r*r)
}

