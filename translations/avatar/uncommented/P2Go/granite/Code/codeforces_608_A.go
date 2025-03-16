
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var n, s int
    fmt.Fscanf(in, "%d %d\n", &n, &s)
    c := 0
    for i := 0; i < n; i++ {
        var f, t int
        fmt.Fscanf(in, "%d %d\n", &f, &t)
        x := t - (s - f)
        if x > c {
            c = x
        }
    }
    fmt.Fprintf(out, "%d\n", s+c)
    out.Flush()
}
