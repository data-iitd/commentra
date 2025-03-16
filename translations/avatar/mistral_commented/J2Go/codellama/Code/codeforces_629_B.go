
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n int
    fmt.Scan(&n)

    var FfriendPerDay [367]int
    var MfriendPerDay [367]int
    var answer int

    for i := 0; i < n; i++ {
        var c string
        fmt.Scan(&c)
        var a int
        fmt.Scan(&a)
        var b int
        fmt.Scan(&b)

        for j := a; j <= b; j++ {
            if c == "M" {
                MfriendPerDay[j]++
            } else {
                FfriendPerDay[j]++
            }

            if MfriendPerDay[j] < FfriendPerDay[j] {
                if MfriendPerDay[j] > answer {
                    answer = MfriendPerDay[j]
                }
            } else {
                if FfriendPerDay[j] > answer {
                    answer = FfriendPerDay[j]
                }
            }
        }
    }

    fmt.Println(answer * 2)
}

