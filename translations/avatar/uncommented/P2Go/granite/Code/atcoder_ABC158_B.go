
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    in  = bufio.NewReader(os.Stdin)
    inf = 0x3f3f3f3f
)

func main() {
    const mod = 1e9 + 7
    var n, a, b int
    fmt.Fscanf(in, "%d%d%d\n", &n, &a, &b)
    ans := 0
    rep := n / (a + b)
    ans += rep * a
    res := n - rep*(a+b)
    ans += min(res, a)
    fmt.Println(ans)
}

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

