
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    n, _ := strconv.Atoi(read())
    x := strings.Split(read(), " ")
    a := make([]int, 0)
    b := make([]int, 0)
    for i := 0; i < n; i++ {
        v, _ := strconv.Atoi(x[i])
        if i%2 == 0 {
            a = append(a, v)
        } else {
            b = append(b, v)
        }
    }
    cnta := make([]int, 100002)
    cntb := make([]int, 100002)
    vala := 0
    vala1 := 0
    maxCnta := 0
    maxCnta1 := 0
    for i := 0; i < len(a); i++ {
        cnta[a[i]]++
    }
    for i := 0; i < len(a); i++ {
        if maxCnta < cnta[a[i]] {
            vala = a[i]
            maxCnta = cnta[a[i]]
        }
    }
    for i := 0; i < len(a); i++ {
        if maxCnta1 < cnta[a[i]] && vala!= a[i] {
            maxCnta1 = cnta[a[i]]
            vala1 = a[i]
        }
    }
    valb := 0
    valb1 := 0
    maxCntb := 0
    maxCntb1 := 0
    for i := 0; i < len(b); i++ {
        cntb[b[i]]++
    }
    for i := 0; i < len(b); i++ {
        if maxCntb < cntb[b[i]] {
            valb = b[i]
            maxCntb = cntb[b[i]]
        }
    }
    for i := 0; i < len(b); i++ {
        if maxCntb1 < cntb[b[i]] && valb!= b[i] {
            maxCntb1 = cntb[b[i]]
            valb1 = b[i]
        }
    }
    if valb!= vala {
        res := 0
        for i := 0; i < len(a); i++ {
            if a[i]!= vala {
                res++
            }
        }
        for i := 0; i < len(b); i++ {
            if b[i]!= valb {
                res++
            }
        }
        fmt.Println(res)
    } else {
        resa := 0
        resb := 0
        resa1 := 0
        resb1 := 0
        for i := 0; i < len(a); i++ {
            if a[i]!= vala {
                resa++
            }
            if a[i]!= vala1 {
                resa1++
            }
        }
        for i := 0; i < len(b); i++ {
            if b[i]!= valb {
                resb++
            }
            if b[i]!= valb1 {
                resb1++
            }
        }
        fmt.Println(min(resa+resb1, resa1+resb))
    }
    out.Flush()
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := in.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return string(buf)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
