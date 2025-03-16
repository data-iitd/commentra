
package main

import (
    "fmt"
    "strings"
)

func generateString() string {
    var sb strings.Builder
    for i := 1; i <= 1000; i++ {
        sb.WriteString(fmt.Sprintf("%d", i))
    }
    return sb.String()
}

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(generateString()[n-1])
}

