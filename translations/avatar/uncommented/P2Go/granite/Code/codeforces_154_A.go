
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    reader *bufio.Reader
    writer *bufio.Writer
)

func check(err error) {
    if err!= nil {
        panic(err)
    }
}

func main() {
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var s string
    fmt.Fscanln(reader, &s)
    var n int
    fmt.Fscanln(reader, &n)
    ans := 0
    for i := 0; i < n; i++ {
        var x string
        fmt.Fscanln(reader, &x)
        a, b := 0, 0
        for j := 0; j < len(s); j++ {
            if string(s[j]) == string(x[0]) {
                a++
            } else if string(s[j]) == string(x[1]) {
                b++
            } else {
                ans += min(a, b)
                a, b = 0, 0
            }
        }
        ans += min(a, b)
    }
    fmt.Fprintln(writer, ans)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

