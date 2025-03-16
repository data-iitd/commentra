package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    s := strings.TrimSpace(os.Args[1])
    a, z := 0, 0
    for i := 0; i < len(s); i++ {
        if s[i] == 'A' {
            a = i
            break
        }
    }
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 'Z' {
            z = i
            break
        }
    }
    fmt.Println(strconv.Itoa(z - a + 1))
}

