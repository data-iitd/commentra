
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    defer writer.Flush()

    var t int
    fmt.Fscanf(reader, "%d", &t)

    for i := 0; i < t; i++ {
        var a int
        fmt.Fscanf(reader, "%d", &a)
        fmt.Fprintf(writer, "%d\n", 1)
    }
}

