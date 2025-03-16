

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func isLatinLetter(c rune) bool {
    return c >= 'a' && c <= 'z'
}

func isPunctuation(c rune) bool {
    return c == '.' || c == ',' || c == '!' || c == '?'
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    words := strings.FieldsFunc(text, func(c rune) bool {
        return!isLatinLetter(c) &&!isPunctuation(c)
    })
    result := ""
    for i, word := range words {
        if i > 0 {
            result += " "
        }
        result += word
    }
    fmt.Println(result)
}

