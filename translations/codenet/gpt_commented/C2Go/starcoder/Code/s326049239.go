package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a, c, k, b int
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        a, _ = strconv.Atoi(scanner.Text())
        c = 0
        k = 0
        if a < 3 {
            fmt.Println("0")
        } else {
            b = a
            for a > 0 {
                b--
                c++
                if c == 3 {
                    k++
                    c = 0
                }
            }
            fmt.Println(k)
        }
    }
}

