
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
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLineString()))
    m := make([][]int, n)
    for i := 0; i < n; i++ {
        line := strings.TrimSpace(reader.ReadLineString())
        parts := strings.Split(line, " ")
        m[i] = make([]int, len(parts))
        for j := 0; j < len(parts); j++ {
            m[i][j], _ = strconv.Atoi(parts[j])
        }
    }
    sort.Slice(m, func(i, j int) bool {
        return m[i][1] > m[j][1]
    })
    a := m[0]
    for i := 1; i < n; i++ {
        if m[i][1] > a[1] {
            fmt.Println("Happy Alex")
            return
        }
        a = m[i]
    }
    fmt.Println("Poor Alex")
}
