
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n, q int
    var c []byte
    var range [][]int

    fmt.Scan(&n, &q)
    c = make([]byte, n)
    range = make([][]int, q)
    for i := 0; i < q; i++ {
        range[i] = make([]int, 2)
    }

    for i := 0; i < n; i++ {
        c[i], _ = strconv.Atoi(os.Args[i+1])
    }

    for i := 0; i < q; i++ {
        fmt.Scan(&range[i][0], &range[i][1])
    }

    var frag []int
    var rui []int

    frag = make([]int, n+1)
    rui = make([]int, n+1)

    for i := 2; i <= n; i++ {
        if c[i-2] == 1 && c[i-1] == 2 {
            frag[i]++
        }
        rui[i] = rui[i-1] + frag[i]
    }

    for i := 0; i < q; i++ {
        left := range[i][0]
        right := range[i][1]
        fmt.Println(rui[right] - rui[left])
    }
}

