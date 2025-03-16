
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n int
    var f int
    var k int
    var j int
    var i int
    var t int

    n, _ = strconv.Atoi(os.Args[1])
    a := make([]int, n)

    for i = 0; i < n; i++ {
        a[i], _ = strconv.Atoi(os.Args[i+2])
    }

    for k = 0; k < n; k++ {
        t = a[k]
        for i = 0; i < n; i++ {
            if i != k {
                for j = 0; j < n-1; j++ {
                    if i != j && t == (a[i] + a[j]) {
                        f = 1
                        break
                    }
                }
                if f == 1 {
                    break
                }
            }
        }
        if f == 1 {
            fmt.Println(k+1, j+1, i+1)
            f = 0
        }
    }

    if f == 0 {
        fmt.Println(-1)
    }
}

