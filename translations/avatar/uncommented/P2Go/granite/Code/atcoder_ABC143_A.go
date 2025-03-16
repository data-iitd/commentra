
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
    A, _ := strconv.Atoi(read())
    B, _ := strconv.Atoi(read())
    ans := A - 2*B
    if ans < 0 {
        ans = 0
    }
    fmt.Println(ans)
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
    return string(buf)
}

