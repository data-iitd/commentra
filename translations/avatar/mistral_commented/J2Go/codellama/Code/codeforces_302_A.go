
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n, k int
    var arr []int

    fmt.Scan(&n, &k)

    arr = make([]int, n)

    for i := 0; i < n; i++ {
        fmt.Scan(&arr[i])
    }

    var o, e int

    for i := 0; i < n; i++ {
        if arr[i] == 1 {
            o++
        } else {
            e++
        }
    }

    var res string

    for i := 0; i < k; i++ {
        var l, r int
        fmt.Scan(&l, &r)

        if (r-l+1)%2 == 1 {
            res += "0\n"
        } else {
            if (r-l+1)/2 <= o {
                res += "1\n"
            } else {
                res += "0\n"
            }
        }
    }

    fmt.Print(res)
}

