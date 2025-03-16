
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
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    n := []rune(text)
    s := false
    for _, v := range n {
        if v == '.' {
            if s {
                fmt.Print(1)
                s = false
            } else {
                fmt.Print(0)
                s = false
            }
        } else {
            if s {
                fmt.Print(2)
                s = false
            } else {
                s = true
            }
        }
    }
    fmt.Println()
}

