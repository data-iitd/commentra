
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
    var n int
    fmt.Fscanf(in, "%d\n", &n)

    var l, r int
    fmt.Fscanf(in, "%d %d\n", &l, &r)

    var id int
    for i := 1; i < n; i++ {
        var li, ri int
        fmt.Fscanf(in, "%d %d\n", &li, &ri)

        if li <= l && r <= ri {
            id = i
        } else if li < l || r < ri {
            id = n
        } else {
            l = int(math.Min(float64(l), float64(li)))
            r = int(math.Max(float64(r), float64(ri)))
        }
    }

    if id == n {
        fmt.Fprintln(out, -1)
    } else {
        fmt.Fprintln(out, id+1)
    }

    out.Flush()
}

