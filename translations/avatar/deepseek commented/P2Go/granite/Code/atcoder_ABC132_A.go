

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    S, _ := reader.ReadString('\n')
    S = strings.TrimSpace(S)
    c := make(map[rune]int)
    for _, r := range S {
        c[r]++
    }
    if len(c)!= 2 {
        fmt.Println("No")
        return
    }
    for _, v := range c {
        if v!= 2 {
            fmt.Println("No")
            return
        }
    }
    fmt.Println("Yes")
}

