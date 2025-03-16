
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
    n, _ := strconv.Atoi(read())
    t := 0
    for i := 0; i < n; i++ {
        if i+1&1 == 1 {
            t++
        }
    }
    fmt.Fprintf(out, "%f\n", float64(t)/float64(n))
    out.Flush()
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := in.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return strings.TrimSpace(string(buf))
}

