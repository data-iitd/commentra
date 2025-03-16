package main

import (
    "fmt"
    "strings"
)

func main() {
    var n int
    fmt.Scanf("%d\n", &n)

    for i := 0; i < n; i++ {
        var s string
        fmt.Scanf("%s\n", &s)

        st := make(map[string]bool)
        st[s] = true

        for j := 1; j < len(s); j++ {
            var res string
            for k := 0; k < j; k++ {
                res += string(s[k])
            }

            var res2 string
            for k := j; k < len(s); k++ {
                res2 += string(s[k])
            }

            t := res
            res = Reverse(res)
            t2 := res2
            res2 = Reverse(res2)

            st[t+t2] = true
            st[t2+t] = true

            st[t+res2] = true
            st[res2+t] = true

            st[res+t2] = true
            st[t2+res] = true

            st[res+res2] = true
            st[res2+res] = true
        }

        fmt.Printf("%d\n", len(st))
    }
}

func Reverse(s string) string {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return string(r)
}

