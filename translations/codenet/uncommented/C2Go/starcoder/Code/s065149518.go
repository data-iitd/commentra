package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n, x, y int
    var fld [21][21]int
    var m int
    var buf string
    var a, d int
    var err error
    for {
        if _, err = fmt.Scanf("%d", &n); err!= nil {
            break
        }
        if n == 0 {
            break
        }
        x = 10
        y = 10
        for i := 0; i < 21; i++ {
            for j := 0; j < 21; j++ {
                fld[i][j] = 0
            }
        }
        for i := 0; i < n; i++ {
            if _, err = fmt.Scanf("%d %d", &a, &d); err!= nil {
                break
            }
            fld[d][a] = 1
        }
        if _, err = fmt.Scanf("%d", &m); err!= nil {
            break
        }
        for i := 0; i < m; i++ {
            if _, err = fmt.Scanf("%s %d", &buf, &a); err!= nil {
                break
            }
            switch buf[0] {
            case 'N':
                d = 0
            case 'E':
                d = 1
            case 'S':
                d = 2
            case 'W':
                d = 3
            }
            for j := 0; j < a; j++ {
                d % 2 == 0? x-- : x++
                d == 0? y-- : d == 1? y++ : d == 2? y++ : y--
                if fld[y][x] == 1 {
                    fld[y][x] = 0
                    n--
                }
            }
        }
        fmt.Printf("%s\n", n == 0? "Yes" : "No")
    }
}

