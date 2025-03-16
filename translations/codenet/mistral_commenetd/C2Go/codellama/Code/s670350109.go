
package main

import (
    "fmt"
    "strings"
)

func main() {
    var str1, str2, temp string
    var i, j, t int

    fmt.Scan(&str1)
    fmt.Println("First string:", str1)

    fmt.Scan(&str2)
    fmt.Println("Second string:", str2)

    i = len(str1)
    t = i - 1

    if len(str1) != len(str2) {
        fmt.Println("NO")
    } else {
        j = 0
        for str1[j] != '\0' {
            temp[j] = str1[t]
            j++
            t--
        }

        t = 0
        i = 0
        for temp[i] != '\0' {
            if temp[i] == str2[i] {
                t++
            }
            i++
        }

        if len(str2) == t {
            fmt.Println("YES")
        } else if len(str2) != t {
            fmt.Println("NO")
        }
    }
}

