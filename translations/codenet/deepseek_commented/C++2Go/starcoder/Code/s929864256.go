<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
    var a, b int
    fmt.Scan(&a, &b)
    fmt.Println(max(a+b, max(a-b, a*b)))
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

