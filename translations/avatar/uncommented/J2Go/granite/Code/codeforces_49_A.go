
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
lastChar := text[len(text)-1]
if lastChar == '?' {
lastChar = text[len(text)-2]
}
if strings.ToLower(string(lastChar)) == "a" || strings.ToLower(string(lastChar)) == "e" || strings.ToLower(string(lastChar)) == "i" || strings.ToLower(string(lastChar)) == "o" || strings.ToLower(string(lastChar)) == "u" || strings.ToLower(string(lastChar)) == "y" {
fmt.Println("YES")
} else {
fmt.Println("NO")
}
}

