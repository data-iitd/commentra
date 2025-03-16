
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
    for _, char := range text {
        if char!= 'B' {
            result += string(char)
        } else {
            result = result[:len(result)-1]
        }
    }

    fmt.Println(result)
}

