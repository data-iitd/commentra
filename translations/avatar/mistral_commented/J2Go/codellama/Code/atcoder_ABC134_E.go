package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n int
    var err error
    var scanner *bufio.Scanner
    var map map[int]int

    scanner = bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)

    scanner.Scan()
    n, err = strconv.Atoi(scanner.Text())
    if err != nil {
        panic(err)
    }

    map = make(map[int]int)

    for i := 0; i < n; i++ {
        scanner.Scan()
        num, err := strconv.Atoi(scanner.Text())
        if err != nil {
            panic(err)
        }

        if _, ok := map[num]; !ok {
            map[num] = 1
        } else {
            map[num]++
        }
    }

    var ans int
    for key, val := range map {
        ans += val
    }

    fmt.Println(ans)
}

