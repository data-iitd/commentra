
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
    result := ""
    s := false
    for _, char := range text {
        if char == '.' {
            if s {
                result += "1"
                s = false
            } else {
                result += "0"
            }
        } else {
            if s {
                result += "2"
                s = false
            } else {
                s = true
            }
        }
    }
    fmt.Println(result)
}

