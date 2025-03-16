
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
    fmt.Println("Enter the number of tuples: ")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    m := make([][]int, n)
    for i := 0; i < n; i++ {
        fmt.Println("Enter tuple {}: ".format(i+1))
        m[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    }
    sort.Slice(m, func(i, j int) bool { return m[i][1] > m[j][1] })
    a := m[0]
    for _, i := range m[1:] {
        if i[1] > a[1] {
            fmt.Println("Happy Alex")
            break
        }
        a = i
    } else {
        fmt.Println("Poor Alex")
    }
}

