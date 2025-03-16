
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    reader *bufio.Reader = bufio.NewReader(os.Stdin)
    writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func main() {
    var N int
    fmt.Fscanf(reader, "%d\n", &N)
    i := 1
    ans := 0
    for 10 <= N {
        ans += (10 - 1)
        i += 2
    }
    ans += max(0, N-10+1)
    fmt.Fprintf(writer, "%d\n", ans)
    writer.Flush()
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

