
package main

import (
    "fmt"
    "strconv"
)

func main() {
    var n int
    fmt.Scan(&n)

    a := make([]int, n + 1)
    b := make([]int, n + 1)
    num := make([]int, n + 1)

    for i := 1; i <= n; i++ {
        fmt.Scan(&a[i], &b[i])
    }

    ss := ""
    ans := 0
    st := make([]bool, n + 1)

    for i := 1; i <= n; i++ {
        if a[i] == 1 {
            st[i] = true
            sb := ""
            x := b[i]
            sss := strconv.Itoa(i)
            sb += " " + sss
            s := 1

            for st[x] == false && num[x] == 1 && x != 0 && a[x] != 1 {
                sss = strconv.Itoa(x)
                sb += " " + sss
                st[x] = true
                x = b[x]
                s++
            }

            if s > ans {
                ans = s
                ss = sb
            }
        }
    }

    fmt.Println(ans)
    fmt.Println(ss)
}

