
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
    q, r := n/m, n%m
    a := make([]int, m)
    for i := 0; i < m; i++ {
        a[i] = q
    }
    for i := 0; i < r; i++ {
        a[i]++
    }
    for i := 0; i < m; i++ {
        fmt.Fprint(out, a[i], " ")
    }
    fmt.Fprintln(out)
    out.Flush()
}

func readIntPair() (int, int) {
    s := readLine()
    n, _ := strconv.Atoi(s[:len(s)/2])
    m, _ := strconv.Atoi(s[len(s)/2:])
    return n, m
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

