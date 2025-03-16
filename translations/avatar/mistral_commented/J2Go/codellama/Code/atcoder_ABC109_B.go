
package main

import (
    "fmt"
    "strings"
)

func main() {
    var N int
    fmt.Scan(&N)

    var map = make(map[int]string)

    for i := 0; i < N; i++ {
        var s string
        fmt.Scan(&s)
        map[i] = s
    }

    var ans = true
    var past = make(map[int]string)
    var next = ""

    for i := 0; i < N; i++ {
        if _, ok := past[i]; ok {
            ans = false
            break
        }
        past[i] = map[i]

        if i != 0 {
            if !strings.HasPrefix(map[i], next) {
                ans = false
                break
            }
        }
        next = map[i][len(map[i])-1:]
    }

    if ans {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

