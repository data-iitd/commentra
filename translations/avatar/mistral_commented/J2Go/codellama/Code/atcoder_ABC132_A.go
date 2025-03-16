
package main

import (
    "fmt"
    "strings"
)

func main() {
    var s string
    fmt.Scan(&s)
    targ := []rune(s)

    map := make(map[rune]int)

    for i := 0; i < len(targ); i++ {
        currentChar := targ[i]

        if _, ok := map[currentChar]; !ok {
            map[currentChar] = 1
        } else {
            map[currentChar]++
        }
    }

    ok := true

    for key, value := range map {
        if value != 2 {
            ok = false
            break
        }
    }

    if ok && len(map) == 2 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

