package main

import (
    "fmt"
    "strconv"
)

func main() {
    var n int
    fmt.Scan(&n)
    s := ""
    for n > 0 {
        x := n % 2
        n /= 2
        s += strconv.Itoa(x)
    }
    ans := 0
    for i := 0; i < len(s); i++ {
        if s[i] == '1' {
            ans++
        }
    }
    fmt.Println(ans)
}

