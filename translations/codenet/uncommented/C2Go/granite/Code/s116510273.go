
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    mes, _ := reader.ReadString('\n')
    mes = strings.TrimSpace(mes)
    fmt.Printf("%c%d%c\n", mes[0], len(mes)-2, mes[len(mes)-1])
}

