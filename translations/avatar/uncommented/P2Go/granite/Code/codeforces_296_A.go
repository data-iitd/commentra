
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
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLine().String()))
    m := strings.Split(strings.TrimSpace(reader.ReadLine().String()), " ")
    possible := true
    for _, v := range m {
        if strings.Count(strings.Join(m, " "), v) >= n/2+1 {
            possible = false
            break
        }
    }
    fmt.Println("YES")
    if!possible {
        fmt.Println("NO")
    }
}
