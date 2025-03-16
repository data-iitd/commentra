
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
    text = strings.Replace(text, "C", " ", 1)
    text = strings.Replace(text, "O", " ", 1)
    fmt.Println(text)
}

