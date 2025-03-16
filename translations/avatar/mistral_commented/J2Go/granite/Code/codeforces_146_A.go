

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n int
    var str string
    fmt.Fscan(reader, &n)
    fmt.Fscan(reader, &str)
    l := strings.Split(str, "")
    t := 0
    for i := 0; i < n; i++ {
        if l[i]!= "4" && l[i]!= "7" {
            t = 1
            break
        }
    }
    if t == 1 {
        fmt.Println("NO")
    } else {
        x := 0
        y := 0
        for i := 0; i < n/2; i++ {
            x, _ = strconv.Atoi(l[i])
            x += x
        }
        for i := n - 1; i > n/2-1; i-- {
            y, _ = strconv.Atoi(l[i])
            y += y
        }
        if x == y {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}

This Go code is equivalent to the Java code provided. It reads the input from the standard input, checks if the string contains only '4' and '7', and then calculates the sum of the digits in the first half of the string and compares it with the sum of the digits in the second half of the string. If they are equal, it prints "YES", otherwise it prints "NO".

Let me know if you need any further assistance.