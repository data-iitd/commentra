
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
    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)

    a := -1
    z := -1

    for i, char := range s {
        if char == 'A' {
            a = i
            break
        }
    }

    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 'Z' {
            z = i
            break
        }
    }

    if a!= -1 && z!= -1 {
        fmt.Println(z - a + 1)
    }

    // 