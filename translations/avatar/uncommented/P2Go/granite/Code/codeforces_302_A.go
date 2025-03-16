
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    n, m := readIntPair()
    sa := 0
    for {
        s, err := in.ReadByte()
        if err!= nil {
            break
        }
        if s == '-' {
            sa++
        }
    }
    sa = min(n-sa, sa)
    for i := 0; i < m; i++ {
        a, b := readIntPair()
        b -= a
        if b%2 == 1 && b <= sa*2 {
            fmt.Fprint(out, "1\n")
        } else {
            fmt.Fprint(out, "0\n")
        }
    }
    out.Flush()
}

func readIntPair() (int, int) {
    s, _ := in.ReadBytes('\n')
    a, _ := strconv.Atoi(string(s[:len(s)-1]))
    s, _ = in.ReadBytes('\n')
    b, _ := strconv.Atoi(string(s[:len(s)-1]))
    return a, b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
