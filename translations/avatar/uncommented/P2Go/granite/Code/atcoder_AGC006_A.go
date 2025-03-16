
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
    var n int
    fmt.Fscanf(in, "%d\n", &n)
    s := make([]byte, n)
    fmt.Fscanf(in, "%s\n", &s)
    t := make([]byte, n)
    fmt.Fscanf(in, "%s\n", &t)
    if string(s) == string(t) {
        fmt.Fprintf(out, "%d\n", n)
    } else {
        cnt := 0
        for i := 0; i < n; i++ {
            for j := 0; j < n-i; j++ {
                if s[i+j]!= t[j] {
                    break
                }
                if j == n-i-1 {
                    cnt = n - i
                }
            }
        }
        fmt.Fprintf(out, "%d\n", 2*n-cnt)
    }
    out.Flush()
}
