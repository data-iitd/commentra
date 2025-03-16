

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

    cnt := make([]int, 5)
    for i := 0; i < n; i++ {
        var s string
        fmt.Fscanf(in, "%s\n", &s)

        switch s[0] {
        case 'M':
            cnt[0]++
        case 'A':
            cnt[1]++
        case 'R':
            cnt[2]++
        case 'C':
            cnt[3]++
        case 'H':
            cnt[4]++
        }
    }

    res := int64(0)
    for i := 0; i < 5; i++ {
        for j := i + 1; j < 5; j++ {
            for k := j + 1; k < 5; k++ {
                res += int64(cnt[i]) * int64(cnt[j]) * int64(cnt[k])
            }
        }
    }

    fmt.Fprintf(out, "%d\n", res)
    out.Flush()
}

