
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
    result := ""
    i := 0
    for i < len(text) {
        if text[i] == '.' {
            result += "0"
        } else {
            i++
            if text[i] == '.' {
                result += "1"
            } else {
                result += "2"
            }
        }
        i++
    }
    fmt.Println(result)
}

