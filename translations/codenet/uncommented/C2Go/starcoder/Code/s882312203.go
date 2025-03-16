package main

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    var s string
    fmt.Scanf("%s", &s)

    for j := 0; j < len(s); j++ {
        for i := 0; i < len(s); i++ {
            if i!= j && s[i] == s[j] {
                fmt.Println("no")
                os.Exit(0)
            }
        }
    }

    fmt.Println("yes")
}

