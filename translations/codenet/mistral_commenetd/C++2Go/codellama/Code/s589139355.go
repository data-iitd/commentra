
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    var a int
    var t, h int = 0, 0
    var taro, hana string
    var lt, lh, l int

    fmt.Scan(&a)

    for i := 0; i < a; i++ {
        fmt.Scan(&taro, &hana)
        lt = len(taro)
        lh = len(hana)

        if lt > lh {
            l = lt
        } else {
            l = lh
        }

        tt := 0
        hh := 0

        if taro > hana {
            t = t + 3
        } else if hana > taro {
            h = h + 3
        } else if hana == taro {
            h = h + 1
            t = t + 1
        }
    }

    fmt.Println(t, h)
}

