
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
    mes, _ := reader.ReadString('\n')
    mes = strings.TrimSpace(mes)

    // Logic starts here

    fmt.Printf("%c%d%c\n", mes[0], len(mes)-2, mes[len(mes)-1]) // Print the first character, length - 2 and last character of the input string
}

// 