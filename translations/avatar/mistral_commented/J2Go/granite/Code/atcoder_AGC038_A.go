
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    var H, W, A, B int
    fmt.Fscanf(reader, "%d %d %d %d\n", &H, &W, &A, &B)

    if W < 2*A || H < 2*B {
        fmt.Fprintln(writer, "-1")
        writer.Flush()
        return
    }

    for i := 0; i < H; i++ {
        for j := 0; j < W; j++ {
            if (i < B && j < A) || (i >= B && j >= A) {
                fmt.Fprint(writer, "0")
            } else {
                fmt.Fprint(writer, "1")
            }
        }
        fmt.Fprintln(writer)
    }

    writer.Flush()
}

