
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    r = bufio.NewReader(os.Stdin)
    w = bufio.NewWriter(os.Stdout)
)

func main() {
    var a, b, c, d int
    fmt.Fscanf(r, "%d%d%d%d\n", &a, &b, &c, &d)
    fmt.Fprintf(w, "%d\n", max(a*c, b*d, a*d, b*c))
    w.Flush()
}

func max(a, b, c, d int) int {
    if a > b {
        if c > d {
            return a
        } else {
            return c
        }
    } else {
        if d > c {
            return b
        } else {
            return d
        }
    }
}

