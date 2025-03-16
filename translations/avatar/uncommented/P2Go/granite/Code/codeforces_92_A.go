
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var n, m int
    var err error

    if n, err = readInt(); err!= nil {
        panic(err)
    }
    if m, err = readInt(); err!= nil {
        panic(err)
    }

    i := 1
    for m >= i {
        m -= i
        i = (i % n) + 1
    }
    fmt.Fprintln(out, m)
    out.Flush()
}

func readInt() (int, error) {
    var (
        i int64
        err error
    )

    if i, err = strconv.ParseInt(read(), 10, 64); err!= nil {
        return 0, err
    }

    return int(i), nil
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

    return string(buf)
}
