package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)
    var N, M int
    scanner.Scan()
    N, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    M, _ = strconv.Atoi(scanner.Text())
    black := make([][]int, N+2)
    for i := range black {
        black[i] = make([]int, N+2)
    }
    for m := 1; m <= M; m++ {
        var x, y int
        scanner.Scan()
        x, _ = strconv.Atoi(scanner.Text())
        scanner.Scan()
        y, _ = strconv.Atoi(scanner.Text())
        for xx := x - 1; xx <= x + 1; xx++ {
            for yy := y - 1; yy <= y + 1; yy++ {
                if black[xx][yy]++; black[xx][yy] == 9 {
                    fmt.Println(m)
                    return
                }
            }
        }
    }
    fmt.Println(-1)
}

