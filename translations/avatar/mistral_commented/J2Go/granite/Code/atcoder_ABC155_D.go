

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

var (
    reader *bufio.Reader = bufio.NewReader(os.Stdin)
    writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func main() {
    var n int
    var k int64
    fmt.Fscanf(reader, "%d\n", &n)
    fmt.Fscanf(reader, "%d\n", &k)
    a := make([]int64, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d\n", &a[i])
    }
    sort.Slice(a, func(i, j int) bool {
        return a[i] < a[j]
    })
    const mod = 1000000007
    const inf = 100000000000000000
    l, r := -inf, inf
    for l+1 < r {
        c := (l + r) / 2
        if check(c, a, k) {
            l = c
        } else {
            r = c
        }
    }
    fmt.Fprintf(writer, "%d\n", l)
    writer.Flush()
}

func check(x int64, a []int64, k int64) bool {
    var tot int64
    for _, v := range a {
        if v >= 0 {
            l, r := 0, len(a)
            for l < r {
                c := (l + r) / 2
                if v*a[c] < x {
                    l = c + 1
                } else {
                    r = c
                }
            }
            tot += int64(l)
        } else {
            l, r := 0, len(a)
            for l < r {
                c := (l + r) / 2
                if v*a[c] >= x {
                    l = c + 1
                } else {
                    r = c
                }
            }
            tot += int64(len(a) - l)
        }
        if v*v < x {
            tot--
        }
        if tot/2 < k {
            return true
        }
    }
    return false
}

Translate the above Go code to C++ and end with comment "