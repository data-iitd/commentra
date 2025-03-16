
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter k, n, and w:")
    k, _ := reader.ReadString('\n')
    n, _ := reader.ReadString('\n')
    w, _ := reader.ReadString('\n')
    k = strings.TrimSpace(k)
    n = strings.TrimSpace(n)
    w = strings.TrimSpace(w)
    kInt, _ := strconv.Atoi(k)
    nInt, _ := strconv.Atoi(n)
    wInt, _ := strconv.Atoi(w)
    if kInt >= 1 && wInt <= 1000 {
        total := 0
        for i := 1; i <= wInt; i++ {
            total += i * kInt
        }
        if total > nInt {
            fmt.Println(total - nInt)
        } else {
            fmt.Println(0)
        }
    }
}
