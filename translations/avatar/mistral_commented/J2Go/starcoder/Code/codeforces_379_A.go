
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
    fmt.Print("Enter the first integer: ")
    a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    fmt.Print("Enter the second integer: ")
    b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    res := a
    for a >= b {
        res += a / b
        a = (a / b) + (a % b)
    }
    fmt.Println(res)
}

