

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    r, _ := strconv.Atoi(strings.TrimSpace(readLine()))
    d, _ := strconv.Atoi(strings.TrimSpace(readLine()))
    x, _ := strconv.ParseInt(strings.TrimSpace(readLine()), 10, 64)

    for i := 0; i < 10; i++ {
        x = int64(r*int(x) - d)
        fmt.Fprintln(out, x)
    }

    out.Flush()
}

func readLine() string {
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
    return string(buf)
}

