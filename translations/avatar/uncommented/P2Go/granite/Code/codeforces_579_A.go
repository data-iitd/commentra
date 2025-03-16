
package main

import (
    "bufio"
    "fmt"
    "math"
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
    x := 1
    for math.Log2(float64(n))%1!= 0 {
        x++
        n -= int(math.Pow(2, math.Floor(math.Log2(float64(n)))))
    }
    fmt.Fprintf(out, "%d\n", x)
    out.Flush()
}

