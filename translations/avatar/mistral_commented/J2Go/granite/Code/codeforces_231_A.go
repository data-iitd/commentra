
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var t int
    fmt.Fscan(reader, &t)
    count := 0
    for t > 0 {
        var a, b, c int
        fmt.Fscan(reader, &a, &b, &c)
        if a == 1 || b == 1 || c == 1 {
            count++
        }
        t--
    }
    fmt.Println(count)
}

