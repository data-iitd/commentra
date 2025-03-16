
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
    var N int
    fmt.Fscanf(in, "%d\n", &N)
    n := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Fscanf(in, "%d", &n[i])
    }
    a := 1
    pos := 0
    for i := 1; i < N; i++ {
        if n[pos] > n[i] {
            a++
            pos = i
        }
    }
    fmt.Fprintf(out, "%d\n", a)
    out.Flush()
}

