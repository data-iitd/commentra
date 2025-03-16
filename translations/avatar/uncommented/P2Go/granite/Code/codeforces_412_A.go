
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
    var n, k int
    var v string
    fmt.Fscanf(in, "%d %d\n", &n, &k)
    fmt.Fscanf(in, "%s\n", &v)
    d := []string{"LEFT", "RIGHT"}
    f := k-1 < n-k
    m := int(math.Min(float64(k-1), float64(n-k)))
    a := make([]string, 0, 2*m+len(v))
    for i := 0; i < m; i++ {
        a = append(a, d[f])
    }
    for i := len(v) - 1; i >= 0; i-- {
        a = append(a, "PRINT "+string(v[i]))
        a = append(a, d[!f])
    }
    for i := len(a) - 1; i >= 0; i-- {
        fmt.Fprintln(out, a[i])
    }
    out.Flush()
}

