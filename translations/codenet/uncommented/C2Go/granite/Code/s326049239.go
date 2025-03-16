
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    var a int
    for {
        if _, err := fmt.Fscanf(reader, "%d\n", &a); err!= nil {
            break
        }

        c, k := 0, 0
        if a < 3 {
            fmt.Fprintln(writer, "0")
            continue
        }

        b := a
        for a > 0 {
            a--
            b--
            c++
            if c == 3 {
                k++
                c = 0
            }
        }

        fmt.Fprintln(writer, k)
    }

    writer.Flush()
}

