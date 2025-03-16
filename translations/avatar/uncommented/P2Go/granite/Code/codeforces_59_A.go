
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

    upperCount := 0
    lowerCount := 0
    for _, char := range text {
        if char >= 'A' && char <= 'Z' {
            upperCount++
        } else if char >= 'a' && char <= 'z' {
            lowerCount++
        }
    }

    var result string
    if upperCount > lowerCount {
        result = strings.ToUpper(text)
    } else {
        result = strings.ToLower(text)
    }

    fmt.Println(result)
}
