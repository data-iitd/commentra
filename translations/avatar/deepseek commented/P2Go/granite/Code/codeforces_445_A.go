

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
    fmt.Println("Enter the number of rows and columns:")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(text))
    fmt.Println("Enter the grid:")
    l := make([][]string, n)
    for i := 0; i < n; i++ {
        text, _ := reader.ReadString('\n')
        s := strings.TrimSpace(text)
        l[i] = make([]string, len(s))
        for j := 0; j < len(s); j++ {
            if s[j] == '.' {
                if (i+j)%2 == 0 {
                    l[i][j] = "B"
                } else {
                    l[i][j] = "W"
                }
            } else {
                l[i][j] = string(s[j])
            }
        }
    }
    for i := 0; i < n; i++ {
        fmt.Println(strings.Join(l[i], ""))
    }
}

