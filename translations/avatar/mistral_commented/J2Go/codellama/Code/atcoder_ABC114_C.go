
package main

import (
    "fmt"
    "strconv"
)

func main() {
    var N int
    fmt.Scan(&N)

    i := 357
    c := 0

    for i <= N {
        s := strconv.Itoa(i)

        if s == "357" {
            c++
        }

        var f bool
        for j := 0; j < len(s); j++ {
            a := s[len(s)-1-j]

            if f {
                s = s + string(a)
            } else {
                if a == '3' {
                    s = "5" + s
                    f = true
                } else if a == '5' {
                    s = "7" + s
                    f = true
                } else {
                    s = "3" + s
                    f = true
                }
            }
        }

        if !f {
            s = "3" + s
        }

        i, _ = strconv.ParseInt(s, 10, 64)
    }

    fmt.Println(c)
}

