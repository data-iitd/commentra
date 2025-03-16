
package main

import (
    "fmt"
    "math"
    "sort"
)

const mod = 1000000007

var n, k int64
var a [100000]int64

func main() {
    var i, j int64
    fmt.Scan(&n, &k)
    for i = 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    sort.Slice(a[:n], func(i, j int) bool {
        return a[i] < a[j]
    })
    var l, r int64 = -1e18, 1e18
    for l+1 < r {
        c := (l + r) / 2
        if check(c) {
            l = c
        } else {
            r = c
        }
    }
    fmt.Println(l)
}

func check(x int64) bool {
    var i, j int64
    var tot int64 = 0
    for i = 0; i < n; i++ {
        now := a[i]
        l, r := 0, n
        if now >= 0 {
            for l < r {
                c := (l + r) / 2
                if now*a[c] < x {
                    l = c + 1
                } else {
                    r = c
                }
            }
            tot += l
        } else {
            for l < r {
                c := (l + r) / 2
                if now*a[c] >= x {
                    l = c + 1
                } else {
                    r = c
                }
            }
            tot += n - l
        }
        if now*now < x {
            tot--
        }
        if tot/2 < k {
            return true
        }
    }
    return false
}

