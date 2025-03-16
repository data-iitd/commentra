
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    s := scanner.Text()
    a, z := -1, -1
    for i, v := range s {
        if v == 'A' {
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
    fmt.Println(z - a + 1)
}

