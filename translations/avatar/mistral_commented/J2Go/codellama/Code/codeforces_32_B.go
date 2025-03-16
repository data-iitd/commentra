package main

import (
    "fmt"
    "os"
)

func main() {
    var n string
    fmt.Scan(&n)

    var s bool
    for i := 0; i < len(n); i++ {
        if n[i] == '.' {
            if s {
                fmt.Print(1)
                s = false
            } else {
                fmt.Print(0)
            }
        } else {
            if s {
                fmt.Print(2)
                s = false
            } else {
                s = true
            }
        }
    }
}

