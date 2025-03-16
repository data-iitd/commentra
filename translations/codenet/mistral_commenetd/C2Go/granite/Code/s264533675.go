
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
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
    str = str[:5] + " " + str[6:13] + " " + str[14:]
    fmt.Println(str)
}

