package main

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    str := strings.TrimSpace(string(os.Stdin.Read(1024)))
    max := 0
    cnt := 0
    for _, sc := range str {
        if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
            cnt++
        } else {
            cnt = 0
        }
        if max < cnt {
            max = cnt
        }
    }
    fmt.Println(max)
}

