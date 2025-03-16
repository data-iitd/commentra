

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    var t int
    var err error
    var a, b int

    if t, err = strconv.Atoi(reader.ReadLine()); err!= nil {
        panic(err)
    }

    for i := 0; i < t; i++ {
        if a, err = strconv.Atoi(reader.ReadLine()); err!= nil {
            panic(err)
        }
        if b, err = strconv.Atoi(reader.ReadLine()); err!= nil {
            panic(err)
        }

        fmt.Fprintln(writer, a+b)
    }

    writer.Flush()
}

