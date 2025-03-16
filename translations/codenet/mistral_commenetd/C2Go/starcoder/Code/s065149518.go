
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n, x, y, m int
    var fld [21][21]int
    var buf [2]byte
    var s string
    var err error
    var r *bufio.Reader
    r = bufio.NewReader(os.Stdin)
    for {
        s, err = r.ReadString('\n')
        if err!= nil {
            break
        }
        n, err = strconv.Atoi(strings.TrimSpace(s))
        if err!= nil {
            break
        }
        if n < 0 {
            break
        }
        init(n)
        s, err = r.ReadString('\n')
        if err!= nil {
            break
        }
        m, err = strconv.Atoi(strings.TrimSpace(s))
        if err!= nil {
            break
        }
        move(m)
        fmt.Printf("%s\n", n == 0? "Yes" : "No")
    }
}

func init(i int) {
    var a, b int
<<<<<<< HEAD
    x = y = 10
=======
    x = 10
    y = 10
>>>>>>> 98c87cb78a (data updated)
    for i > 0 {
        s, _ := r.ReadString('\n')
        a, b, _ = strconv.Atoi(strings.TrimSpace(s))
        fld[b][a] = 1
        i--
    }
}

func move(i int) {
    var a, d int
    var buf [2]byte
    for i > 0 {
        s, _ := r.ReadString('\n')
        buf[0], a, _ = s[0], s[2], s[3]
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
        for a > 0 {
            if d%2 == 1 {
                d%2 == 1? x-- : x++
            } else {
                d == 0? y-- : y++
                x += d / 2
            }
            if fld[y][x] == 1 {
                fld[y][x] = 0
                n--
            }
            a--
        }
        i--
    }
}

