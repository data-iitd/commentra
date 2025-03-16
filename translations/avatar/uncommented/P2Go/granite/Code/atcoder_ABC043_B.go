
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
    for _, r := range text {
        if r == '0' || r == '1' {
            result += string(r)
        } else if r == 'B' && len(result)!= 0 {
            result = result[:len(result)-1]
        }
    }
    fmt.Println(result)
}
