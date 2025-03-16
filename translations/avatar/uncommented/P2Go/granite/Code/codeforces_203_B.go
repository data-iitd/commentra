
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, m int
    fmt.Fscanf(reader, "%d %d\n", &n, &m)
    count := make([][]int, n)
    for i := 0; i < n; i++ {
        count[i] = make([]int, n)
    }
    ans := -1
    for k := 0; k < m; k++ {
        var x, y int
        fmt.Fscanf(reader, "%d %d\n", &x, &y)
        x--
        y--
        found := false
        for i := x - 2; i <= x+1; i++ {
            for j := y - 2; j <= y+1; j++ {
                if i >= 0 && i < n && j >= 0 && j < n {
                    count[i][j]++
                    if count[i][j] == 9 {
                        found = true
                    }
                }
            }
        }
        if found {
            ans = k + 1
            break
        }
    }
    fmt.Println(ans)
}
