
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var x, y int
    fmt.Fscanf(in, "%d %d\n", &x, &y)
    a := 0
    for x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2 {
        if a == 1 {
            if y >= 22 {
                y -= 22
            } else if x >= 1 && y >= 12 {
                x -= 1
                y -= 12
            } else {
                x -= 2
                y -= 2
            }
        } else {
            if x >= 2 && y >= 2 {
                x -= 2
                y -= 2
            } else if x >= 1 && y >= 12 {
                x -= 1
                y -= 12
            } else {
                y -= 22
            }
        }
        a = 1 - a
    }
    fmt.Fprintf(out, "%s\n", []string{ "Ciel", "Hanako" }[1-a])
    out.Flush()
}
