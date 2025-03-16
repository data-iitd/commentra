
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    dx = []int{-1, 0, 1, 0}
    dy = []int{0, -1, 0, 1}
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var d int
    scanner.Scan()
    d, _ = strconv.Atoi(scanner.Text())
    for l := 0; l < d; l++ {
        var n int
        scanner.Scan()
        n, _ = strconv.Atoi(scanner.Text())
        if n == 1 {
            fmt.Println("#")
            if l!= d-1 {
                fmt.Println()
            }
            continue
        }
        m := make([][]byte, n+2)
        for i := 0; i < n+2; i++ {
            m[i] = make([]byte, n+2)
            for j := 0; j < n+2; j++ {
                m[i][j] = '#'
            }
            m[i][0] = '.'
            m[i][n+1] = '.'
        }
        m[0][1] =''
        m[n+1][1] =''
        x, y := 1, n
        m[y][x] =''
        flg := 0
        ab := [4]int{2, 2, 2, 2}
        for {
            sum := 0
            for {
                if m[y+dy[flg]*2][x+dx[flg]*2]!= '#' && m[y+dy[flg]][x+dx[flg]]!='' {
                    flg = (flg + 1) % 4
                    //  fmt.Println(sum)
                    break
                }
                m[y+dy[flg]][x+dx[flg]] =''
                y += dy[flg]
                x += dx[flg]
                sum++
            }
            if flg == 3 {
                flg = 0
            }
            if sum == 0 {
                break
            }
            ab[0] = ab[1]
            ab[1] = ab[2]
            ab[2] = sum
            if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
                break
            }
        }
        for i := 1; i <= n; i++ {
            fmt.Println(string(m[i][1 : n+1]))
        }
        if l!= d-1 {
            fmt.Println()
        }
    }
}
