

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    const MAX = 21
    var n, x, y int
    var fld [MAX][MAX]byte
    var m int
    var buf [2]byte
    var err error
    var line string
    var lines []string
    var ok bool
    var s string
    var scanner *bufio.Scanner
    var t int

    scanner = bufio.NewScanner(os.Stdin)
    for {
        if!scanner.Scan() {
            break
        }
        line = scanner.Text()
        lines = strings.Split(line, " ")
        if len(lines) == 0 {
            continue
        }
        s = lines[0]
        t, err = strconv.Atoi(s)
        if err!= nil {
            break
        }
        if t >= 0 {
            init(t)
            if!scanner.Scan() {
                break
            }
            line = scanner.Text()
            s, err = strconv.Unquote(`"` + line + `"`)
            if err!= nil {
                break
            }
            lines = strings.Split(s, " ")
            m, err = strconv.Atoi(lines[0])
            if err!= nil {
                break
            }
            move(m)
            if n == 0 {
                fmt.Println("Yes")
            } else {
                fmt.Println("No")
            }
        } else {
            break
        }
    }
}

func init(i int) {
    var a, b int
    var err error
    var line string
    var lines []string
    var s string
    var scanner *bufio.Scanner

    x = 10
    y = 10
    for i > 0 {
        scanner = bufio.NewScanner(os.Stdin)
        if!scanner.Scan() {
            break
        }
        line = scanner.Text()
        s, err = strconv.Unquote(`"` + line + `"`)
        if err!= nil {
            break
        }
        lines = strings.Split(s, " ")
        a, err = strconv.Atoi(lines[0])
        if err!= nil {
            break
        }
        b, err = strconv.Atoi(lines[1])
        if err!= nil {
            break
        }
        fld[b][a] = 1
        i--
    }
}

func move(i int) {
    var a, d int
    var err error
    var line string
    var lines []string
    var s string
    var scanner *bufio.Scanner

    for i > 0 {
        scanner = bufio.NewScanner(os.Stdin)
        if!scanner.Scan() {
            break
        }
        line = scanner.Text()
        s, err = strconv.Unquote(`"` + line + `"`)
        if err!= nil {
            break
        }
        lines = strings.Split(s, " ")
        d, err = strconv.Atoi(lines[0])
        if err!= nil {
            break
        }
        a, err = strconv.Atoi(lines[1])
        if err!= nil {
            break
        }
        for a > 0 {
            if d%2 == 1 {
                if d > 0 {
                    d--
                    x--
                } else {
                    d++
                    x++
                }
            } else {
                if d > 0 {
                    d -= 2
                    y--
                } else {
                    d += 2
                    y++
                }
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

