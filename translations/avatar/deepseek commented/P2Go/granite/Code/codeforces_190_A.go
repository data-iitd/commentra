

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

    fmt.Print("Enter the first number: ")
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nStr))

    fmt.Print("Enter the second number: ")
    mStr, _ := reader.ReadString('\n')
    m, _ := strconv.Atoi(strings.TrimSpace(mStr))

    if n < 1 {
        if m < 1 {
            fmt.Println(n, m)
            return
        }
        fmt.Println("Impossible")
        return
    }

    if m > n {
        min := m
        max := n + m - 1
        fmt.Println(min, max)
        return
    }

    if m <= n {
        min := n
        max := n + m - 1
        if m == 0 {
            max = n
        }
        fmt.Println(min, max)
        return
    }
}

