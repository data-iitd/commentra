<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "strings"
)

func main() {
    var S string
    fmt.Scan(&S)

    // Reverse all strings
    for i := 0; i < 4; i++ {
        divide[i] = reverse(divide[i])
    }
    S = reverse(S)

    // Divide from both ends
    can := true
    for i := 0; i < len(S); {
        can2 := false
        for j := 0; j < 4; j++ {
            d := divide[j]
            if S[i:i+len(d)] == d {
                can2 = true
                i += len(d)
            }
        }
        if!can2 {
            can = false
            break
        }
    }

    if can {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func reverse(s string) string {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return string(r)
}

