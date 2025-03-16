

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
    fmt.Println("Enter n and k separated by space:")
    text, _ := reader.ReadString('\n')
    n, k := stringToInt64(strings.Split(strings.TrimSpace(text), " "))
    x := int64(0)
    if k <= max(n*n/2, n*n-(n*n/2)) {
        fmt.Println("YES")
        for i := int64(0); i < n; i++ {
            for j := int64(0); j < n; j++ {
                if i%2 == j%2 && x < k {
                    fmt.Print("L")
                    x++
                } else {
                    fmt.Print("S")
                }
            }
            fmt.Println()
        }
    } else {
        fmt.Println("NO")
    }
}

func stringToInt64(str []string) (int64, int64) {
    var n, k int64
    n, _ = strconv.ParseInt(str[0], 10, 64)
    k, _ = strconv.ParseInt(str[1], 10, 64)
    return n, k
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

