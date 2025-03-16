package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    var sum int64
    var min, max int
    var n int
    var m int
    var i int
    var line string
    var err error
    var scanner *bufio.Scanner
    scanner = bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanLines)
    fmt.Scanf("%d\n", &n)
    for i = 0; i < n; i++ {
        fmt.Scanf("%d", &m)
        sum += int64(m)
        if i == 0 {
            min = m
            max = m
        }
        if min > m {
            min = m
        }
        if max < m {
            max = m
        }
    }
    fmt.Printf("%d %d %d\n", min, max, sum)
}

