
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var N int
    fmt.Fscanf(in, "%d\n", &N)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Fscanf(in, "%d\n", &A[i])
        A[i] = (A[i]*N+i)%N
    }
    sort.Ints(A)
    cnt := 0
    for i := 0; i < N; i++ {
        d := A[i] % 2
        if d%2!= i%2 {
            cnt++
        }
    }
    fmt.Fprintf(out, "%d\n", cnt/2)
    out.Flush()
}
