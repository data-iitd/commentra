
// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    w, ans int
    a, b   []int
    f       int
    close   int
    p       string
)

func main() {
    data, _ := os.Open(os.Args[1])
    defer data.Close()
    scanner := bufio.NewScanner(data)
    scanner.Scan()
    w, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    p = scanner.Text()
    a = make([]int, w+1)
    b = make([]int, w+1)
    for i := 1; i <= w; i++ {
        a[i], p = parseInt(p)
    }
    ans = 0
    f = 0
    for i := 1; i <= w; i++ {
        if a[i] == 0 {
            f |= 1
        } else if a[i] < 0 {
            f |= 2
        } else {
            ans += a[i]
        }
    }
    if ans == 0 ||!(f&1)!= 0 {
        fmt.Println(0)
        return
    }
    if!(f&2)!= 0 {
        fmt.Println(ans)
        return
    }
    close = 0
    f = 0
    for i := 1; i <= w; i++ {
        if a[i] == 0 {
            close = 100000000
            f = -1
        } else if a[i] < 0 {
            if f < 0 || close-(i-f) > -a[i] {
                close = -a[i]
                f = i
            }
        } else {
            if f < 0 {
                b[i] = 100000000
            } else {
                k := close - (i - f)
                if k < 0 {
                    k = 0
                }
                b[i] = k
            }
        }
    }
    close = 0
    f = w
    for i := w; i >= 1; i-- {
        if a[i] == 0 {
            close = 100000000
            f = -1
        } else if a[i] < 0 {
            if f < 0 || close-(f-i) > -a[i] {
                close = -a[i]
                f = i
            }
        } else {
            if f < 0 {
                b[i] = 100000000
            } else {
                k := close - (f - i)
                if k < 0 {
                    k = 0
                }
                if k > b[i] {
                    b[i] = k
                }
            }
        }
    }
    for i := 1; i <= w; i++ {
        if a[i] > 0 {
            if b[i] > a[i] {
                ans += a[i]
            } else {
                ans += b[i]
            }
        }
    }
    fmt.Println(ans)
}

func parseInt(s string) (int, string) {
    res := 0
    for ; s!= "" && s[0] <=''; s = s[1:] {
    }
    neg := false
    if s!= "" && s[0] == '-' {
        neg = true
        s = s[1:]
    }
    for ; s!= "" && s[0] >= '0' && s[0] <= '9'; s = s[1:] {
        res *= 10
        res += int(s[0]) - int('0')
    }
    if neg {
        return -res, s
    }
    return res, s
}

