
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
    var a, b int
    var sa, sb string
    fmt.Fscanf(in, "%s %s\n", &sa, &sb)
    a, _ = strconv.Atoi(sa)
    b, _ = strconv.Atoi(sb)
    fmt.Fprintf(out, "%d\n", a*b/100)
    out.Flush()
}

