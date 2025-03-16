
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    reader *bufio.Reader
    writer *bufio.Writer
)

func init() {
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
}

func main() {
    defer writer.Flush()
    var N int
    var V []int
    var C []int
    fmt.Fscanf(reader, "%d\n", &N)
    V = make([]int, N)
    C = make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Fscanf(reader, "%d", &V[i])
    }
    for i := 0; i < N; i++ {
        fmt.Fscanf(reader, "%d", &C[i])
    }
    list := make([]int, 0)
    ans := 0
    X := 0
    Y := 0
    for i := 0; i < N; i++ {
        if V[i]-C[i] > 0 {
            X = V[i]
            Y = C[i]
            list = append(list, X-Y)
        }
    }
    for _, v := range list {
        ans += v
    }
    fmt.Fprintf(writer, "%d\n", ans)
}
