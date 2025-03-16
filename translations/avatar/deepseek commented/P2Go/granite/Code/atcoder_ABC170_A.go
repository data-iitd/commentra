

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    elements := strings.Split(input, " ")
    for i, element := range elements {
        if element == "0" {
            fmt.Println(i + 1)
            break
        }
    }
}
