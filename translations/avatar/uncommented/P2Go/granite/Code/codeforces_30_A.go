
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
    fmt.Println("Enter A, B and n:")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    parts := strings.Split(text, " ")
    A, _ := strconv.Atoi(parts[0])
    B, _ := strconv.Atoi(parts[1])
    n, _ := strconv.Atoi(parts[2])
    for X := -1000; X <= 1000; X++ {
        if A*(X*X*X) == B {
            fmt.Println(X)
            return
        }
    }
    fmt.Println("No solution")
}
