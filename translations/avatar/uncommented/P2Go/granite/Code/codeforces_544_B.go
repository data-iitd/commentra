
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
    n, k := readIntPair()
    if k > max(n*n/2, n*n-(n*n/2)) {
        fmt.Println("NO")
        return
    }
    fmt.Println("YES")
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i%2 == j%2 && k > 0 {
                fmt.Print("L")
                k--
            } else {
                fmt.Print("S")
            }
        }
        fmt.Println()
    }
}

func readIntPair() (int, int) {
    s := readLine()
    sp := strings.Split(s, " ")
    n, _ := strconv.Atoi(sp[0])
    k, _ := strconv.Atoi(sp[1])
    return n, k
}

func readLine() string {
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

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

