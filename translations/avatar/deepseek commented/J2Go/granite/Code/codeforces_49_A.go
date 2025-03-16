
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
    length := len(s)
    ch := byte(0)
    for i := length - 1; i >= 0; i-- {
        if s[i]!='' && s[i]!= '?' {
            ch = s[i]
            break
        }
    }
    ch = byte(strings.ToLower(string(ch)))
    if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
