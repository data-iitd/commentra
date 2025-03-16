
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)
    result := "Yes"
    if!strings.Contains(s, "A") ||!strings.Contains(s, "B") {
        result = "No"
    }
    fmt.Println(result)
}
