
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialX, initialY = 10, 10
    const max = 21
    var n, m int
    var fld [max][max]bool
    for scanner.Scan() {
        if n, _ = strconv.Atoi(scanner.Text()); n == 0 {
            break
        }
        init(n)
        fmt.Fscanf(scanner, "%d\n", &m)
        move(m)
        if n > 0 {
            fmt.Println("No")
        } else {
            fmt.Println("Yes")
        }
    }
}

func init(i int) {
    x, y = initialX, initialY
    fld = make([][]bool, max)
    for i := range fld {
        fld[i] = make([]bool, max)
    }
    for i := 0; i < n; i++ {
        var a, b int
        fmt.Fscanf(scanner, "%d %d\n", &a, &b)
        fld[b][a] = true
    }
}

func move(i int) {
    var a int
    var d int
    var buf string
    for i := 0; i < m; i++ {
        fmt.Fscanf(scanner, "%s %d\n", &buf, &a)
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
            if d%2 == 0 {
                if d == 0 {
                    x--
                } else {
                    x++
                }
            } else {
                if d == 1 {
                    y--
                } else {
                    y++
                }
            }
            if fld[y][x] {
                fld[y][x] = false
                n--
            }
            a--
        }
    }
}

