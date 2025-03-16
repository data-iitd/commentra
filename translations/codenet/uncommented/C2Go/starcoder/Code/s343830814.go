package main

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    var buf [512]byte
    var len int
    fmt.Fscan(os.Stdin, &buf)
    len = len(buf)
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
}

